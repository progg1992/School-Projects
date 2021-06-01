/*
Pierce Rogg
CIS 247C
Week 4 - Composition
5/28/2021
*/

// Required Libraries
#include <iostream>
#include <conio.h>
#include <string>
#include "Glasses.h"
#include "Person.h"
using namespace std;

/// Entry point to the application
int main()
{
	// Create Person and Glasses
	Person p1;
	Glasses g1("Red", 2.50f);

	cout << p1.toString() << endl;

	// Set Name, SSN and Glasses
	p1.setName("George");
	p1.setSSN("222-33-4444");
	p1.setMyGlasses(g1);

	cout << p1.toString() << endl;

	// Change Glasses Anonymously
	p1.setMyGlasses(Glasses("Purple", 1.50f));

	cout << p1.toString() << endl;

	// Show the Glasses for p1

	cout << "\nColor: " << p1.getMyGlasses().getColor() << endl;
	cout << "\nPrescription: " << p1.getMyGlasses().getPrescription() << endl;

	// Write p1 to file
	string result = p1.writeToFile();

	cout << "\n" << result << endl;

	Person secondPerson;

	secondPerson.setName(p1.getName());

	result = secondPerson.readFromFile();
	cout << "\n" << result << endl;

	cout << "\n\nSecond Person's data from file:\n" << endl;
	cout << "\t" << secondPerson.toString() << endl;

	// Pause
	cout << "\nPress any key to continue...";
	_getch();
	return 0;
}