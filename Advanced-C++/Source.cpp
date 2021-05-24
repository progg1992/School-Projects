/*
Pierce Rogg
CIS 247C
Course Project
5/9/2021
*/

// Required Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Prototypes
void saveToFile(string* ptrName);

/// Entry point to the application
int main()
{
	// Variables & Pointers
	string name = "Pierce Rogg";
	string* ptrName = &name;

	// Check the size
	cout << "Size of string variable: " << sizeof(name) << endl;
	cout << "Size of pointer variable: " << sizeof(ptrName) << endl;

	// Save to file
	saveToFile(ptrName);

	// Pause
	cout << endl;
	system("pause");

	return 0;
}

void saveToFile(string* ptrName)
{
	ofstream outToFile("data.txt");

	// If File is open write to it
	if (outToFile.is_open())
	{
		outToFile << *ptrName << endl;

		// Close File
		outToFile.close();

		// Confirmation Message
		cout << "\nData was written to the file!" << endl;
	}
}
