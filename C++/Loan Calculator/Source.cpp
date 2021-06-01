/*
Pierce Rogg
CIS170C
Mar 2021
Course project
*/

// import libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;

void arrayTutorial();
void addLoan();
void deleteLoan();
void findLoan();
void displayAllLoans();

//
const string LOAN_FILENAME = "Loans.csv";

/// Entry point to the application
int main()
{
	srand(time(0));

	string password = "";
	string appPassword = "CIS170C";
	bool success = false;

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the application password: ";
		cin >> password;

		if (password == appPassword)
		{
			success = true;
			break;
		}
		else
		{
			cout << "\nEnter. Invalid password. Remember the password is case sensitive." << endl;
			cout << "Try Again.\n" << endl;
		}
	}

	if (success == true)
		cout << "\nWelcome to the application\n" << endl;
	else
	{
		cout << "\nYour IP address and location has been sent to the FBI.\n";
		system("pause");
		return -1;
	}

	// get input
	int choice = 0;

	do
	{
		// Make Console background Red
		system("color c2");
		// Show Menu
		system("cls");
		cout << "Welcome to The DeVry Student Bank's Loan Calculator\n" << endl;
		cout << "Menu\n" << endl;
		cout << "1) Add A Loan" << endl;
		cout << "2) Delete A Loan" << endl;
		cout << "3) Find A Loan" << endl;
		cout << "4) Display All Loans" << endl;
		cout << "5) Array Tutorial" << endl;
		cout << "6) Quit\n" << endl;

		// Get the User's Choice
		cout << "Enter your Choice: ";
		cin >> choice;


		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\Error!! Please use numbers only. No letters or Characters Allowed!!" << endl;
			choice = -1;
		}
		else
		{
			cin.ignore(100, '\n');
		}

		// Run Code based on the user's choice
		switch (choice)
		{
		case 1:
			// Add
			addLoan();
			break;
		case 2:
			// Delete
			deleteLoan();
			break;
		case 3:
			// Find
			findLoan();
			break;
		case 4:
			// Display All
			displayAllLoans();
			break;
		case 5:
			// Exit
			arrayTutorial();
			break;
		case 6:
			cout << "\nGoodbye! Thanks for using The DeVry Student Bank's Loan Calculator.";
			break;
		default:
			cout << "Please choose option 1 thru 5 only\n" << endl;
			break;
		}

		//pause
		cout << endl;
		system("pause");
	} while (choice != 6);
	return 0;
}

void arrayTutorial()
{
	// Create array
	cout << "\nArray Tutorial\n" << endl;
	cout << "First step: create the array" << endl;
	cout << "\tdatatype arrayName[ size ];" << endl;
	cout << "\t- For example: int numbers[10];      // create integer array with ten 'slots'" << endl;
	cout << endl;
	cout << "Second step: load the array using a for loop" << endl;
	cout << "\tfor( int i = 0; i < arraySize; i++ ) " << endl;
	cout << "\t{" << endl;
	cout << "\t\tarrayName[i] = value;" << endl;
	cout << "\t}" << endl;
	cout << endl;
	cout << "Third step: Display the contents of the array using a for loop" << endl;
	cout << "\tfor( int i = 0; i< arraysize; i++ )" << endl;
	cout << "\t{" << endl;
	cout << "\t\tcout << arrayName[i] << endl;" << endl;
	cout << "\t}" << endl;
	cout << "\n\nHere is the output of the integer array from above" << endl;
	int numbers[10];
	int min = 10;
	int max = 99;
	for (int i = 0; i < 10; i++)
	{
		numbers[i] = rand() % (max - min + 1) + min;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << numbers[i] << endl;
	}
}

void addLoan()
{
	string name, loanAmount, interestRate, years;
	cout << "\nEnter Your Name: ";
	getline(cin, name);
	cout << "Enter Amount of Loan: ";
	getline(cin, loanAmount);
	cout << "Enter Interest Rate: ";
	getline(cin, interestRate);
	cout << "Enter the number of Years: ";
	getline(cin, years);

	// Open File
	ofstream outFile(LOAN_FILENAME, ios::app);

	// Write File
	outFile << name << ',' << ',' << loanAmount << ',' << interestRate << ',' << years << ',' << endl;

	// Close File
	outFile.close();

	// Display Confirmation Message
	cout << "Loan added to the file";
}

void deleteLoan()
{
	// Get Loan to Delete
	string deleteLoan;
	bool found = false;
	cout << "\nEnter your name to delete paid loans: ";
	getline(cin, deleteLoan);

	// Open File and Temp File
	ifstream iFile(LOAN_FILENAME);
	ofstream oFile(LOAN_FILENAME + ".tmp");

	// Read file and write to .tmp file
	while (iFile.peek() > -1)
	{
		string name, loanAmount, interestRate, years;
		getline(iFile, name, ',');
		getline(iFile, loanAmount, ',');
		getline(iFile, interestRate, ',');
		getline(iFile, years, ',');

		if (name == deleteLoan)
		{
			found = true;
		}
		else
		{
			// Write Loan to .tmp file
			oFile << name << ',' << ',' << loanAmount << ',' << interestRate << ',' << years << ',' << endl;

		}
	}

	// Close Files
	iFile.close();
	oFile.close();

	// Delete Old File
	remove(LOAN_FILENAME.c_str());

	// Rename .tmp to Loan.csv
	rename((LOAN_FILENAME + ".tmp").c_str(), LOAN_FILENAME.c_str());

	// Display Confirmation or Error Message
	if (found)
		cout << "\nLoan was deleted" << endl;
	else
		cout << "\n Loan could not be deleted. Please call your local branch." << endl;
}

void findLoan()
{
	string loanOwner;
	bool found = false;

	cout << "\nEnter Your Name to Find Your Loans: ";
	getline(cin, loanOwner);

	// Open File
	ifstream iFile(LOAN_FILENAME);
	if (iFile.is_open())
	{
		// Read File until we find the drink
		while (iFile.peek() > -1)
		{
			string name, loanAmount, interestRate, years;
			getline(iFile, name, ',');
			getline(iFile, loanAmount, ',');
			getline(iFile, interestRate, ',');
			getline(iFile, years, ',');

			if (name == loanOwner)
			{
				found = true;
				cout << "\n" << name << " " << loanAmount << " " << interestRate << " " << years << endl;
				cout << endl;
				break;
			}
		}

		// Close File
		iFile.close();

		// Display Not Found Message
		if (!found)
		{
			cout << "\n" << loanOwner << " does not have any loans with us" << endl;
		}
	}
}

void displayAllLoans()
{
	string name, loanAmount, interestRate, years;

	// Show the Report
	cout << "\nDevry Student's Bank Loan Database\n" << endl;
	cout << left << setw(15) << "Name" << left << setw(7) << "Amount" << left << setw(5) << "Interet Rate" << left << setw(3) << "Years" << endl;

	// Open File
	ifstream inFile(LOAN_FILENAME);

	if (inFile.is_open())
	{
		while (inFile.peek() > -1)
		{
			getline(inFile, name, ',');
			getline(inFile, loanAmount, ',');
			getline(inFile, interestRate, ',');
			getline(inFile, years, ',');

			// Display All Loans
			cout << left << setw(15) << name << left << setw(7) << loanAmount << left << setw(5) << interestRate << left << setw(3) << years << endl;

		}

		// Close File
		inFile.close();
	}
}