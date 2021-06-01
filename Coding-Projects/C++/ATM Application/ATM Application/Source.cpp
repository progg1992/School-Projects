/*
Pierce Rogg
CIS 247C
ATM Application
5/8/2021
*/

// Required Libraries
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

// Prototypes
void deposit( double* ptrBalance );
void withdrawal(double* ptrBalance, float dailyLimit);
void withdrawal(double* ptrBalance, float dailyLimit, float amount);

/// Entry point to the application
int main()
{
	// Constant Variables
	const int EXIT_VALUE = 5;
	const float DAILY_LIMIT = 400.0f;
	const string FILENAME = "Account.txt";

	// Initializing balance
	double balance = 0.0;

	// Check if Account.txt exists
	ifstream iFile(FILENAME.c_str());
	if (iFile.is_open())
	{
		// Read begining balance
		iFile >> balance;
		iFile.close();
	}
	else
	{
		// Generate Random starting Balance
		srand(time(0));
		const int MIN = 1000;
		const int MAX = 10000;
		balance = rand() % (MAX - MIN + 1) + MIN;
	}
	

	cout << fixed << setprecision(2) << "Starting Balance: $" << balance << endl;

	// Pointer for balance
	double* ptrBalance = &balance;

	// Pause before clearing and moving on
	cout << "\nPress any key to continue...";
	_getch();

	// Intialize loop variable
	short choice = 0;

	do
	{
		// Application Menu
		system("cls");
		cout << "Menu\n" << endl;
		cout << "1) Deposit" << endl;
		cout << "2) Withdrawal" << endl;
		cout << "3) Check Balance" << endl;
		cout << "4) Quick $40" << endl;
		cout << "5) Exit" << endl;

		// Get User's Choice
		cout << "Please Enter your Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			deposit(ptrBalance);
			break;
		case 2:
			withdrawal(ptrBalance, DAILY_LIMIT);
			break;
		case 3:
			cout << fixed << setprecision(2) << "\nCurrent Balance: $" << balance << endl;
			break;
		case 4:
			withdrawal(ptrBalance, DAILY_LIMIT, 40.0f);
			break;
		case 5:
			cout << "\nGoodbye" << endl;
			break;
		default:
			cout << "ERROR!! Please choose from the Menu." << endl;
			break;
		}

		// Pause
		cout << "\nPress any key to continue...";
		_getch();
	} 	while (choice != EXIT_VALUE);

	// Write new Balance to File
	ofstream oFile(FILENAME.c_str());
	oFile << balance << endl;
	oFile.close();

	return 0;

	// Pause
	cout << "\nPress any key to continue...";
	_getch();
	return 0;
}

void deposit(double* ptrBalance)
{
	float deposit = 0.0f;

	do
	{
		cout << "\nEnter deposit amount: ";
		cin >> deposit;
		
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT16_MAX, '\n');
			cout << "\nERROR!! Please use numbers only.\n" << endl;
			deposit = -1;
			continue;
		}
		else if (deposit < 0.0f)
		{
			cout << "\nERROR!! Invalid Deposit Amount. Positive numbers only.\n" << endl;
		}
	} while (deposit < 0.0f);

	// Get value from pointer
	*ptrBalance += deposit;

	cout << fixed << setprecision(2) << "\nCurrent ptrBalance: $" << *ptrBalance << endl;
}

void withdrawal(double* ptrBalance, float dailyLimit)
{
	float amount = 0.0f;

	do
	{
		cout << "\nEnter withdrawal amount: ";
		cin >> amount;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT16_MAX, '\n');
			cout << "\nERROR!! Please use numbers only.\n" << endl;
			amount = -1;
			continue;
		}
		else if (amount < 0.0f)
		{
			cout << "\nERROR!! Invalid Deposit Amount. Positive numbers only.\n" << endl;
		}
	} while (amount < 0.0f);

	withdrawal(ptrBalance, dailyLimit, amount);
}

void withdrawal(double* ptrBalance, float dailyLimit, float amount)
{
	if (amount > dailyLimit)
	{
		cout << "\nERROR!! Amount exceeds daily limit." << endl;
	}
	else if (amount > *ptrBalance)
	{
		cout << "\nERROR!! Insuficient Funds" << endl;
	}
	else
	{
		cout << "\nHere is your cash: $" << amount << endl;
	}

	cout << fixed << setprecision(2) << "\nCurrent Balance: $" << *ptrBalance << endl;
}
