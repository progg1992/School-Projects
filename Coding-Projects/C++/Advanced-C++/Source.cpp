/*
Pierce Rogg
CIS 247C
Course Project
5/24/2021
*/

// Required Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Car.h"
using namespace std;

// Prototypes
void saveToFile(Car* ptrCar);

/// Entry point to the application
int main()
{
	// Create Car Objects
	Engine motor(10, 425);
	Car firstCar;
	Car secondCar("X2345678901234567", "Ford", "Mustang", 2010, 8500.0, 2, false, motor);

	// Check the size
	cout << "Size of Car object: " << sizeof(firstCar) << endl;
	cout << "Size of pointer to Car object: " << sizeof(&firstCar) << endl;
	cout << endl;

	// Delete File if it Exists
	remove("data.txt");

	// Save to file
	saveToFile(&firstCar);
	saveToFile(&secondCar);

	// Pause
	cout << endl;
	system("pause");

	return 0;
}

void saveToFile(Car* ptrCar)
{
	ofstream outToFile("data.txt", ios::app);

	// If File is open write to it
	if (outToFile.is_open())
	{
		outToFile << ptrCar->getVin() << endl;
		outToFile << ptrCar->getMake() << endl;
		outToFile << ptrCar->getModel() << endl;
		outToFile << ptrCar->getYear() << endl;
		outToFile << ptrCar->getPrice() << endl;
		outToFile << ptrCar->getNumDoors() << endl;
		outToFile << ptrCar->getHatchback() << endl;
		outToFile << ptrCar->getMotor().getNumCylinders() << endl;
		outToFile << ptrCar->getMotor().getHorsePower() << endl;

		// Close File
		outToFile.close();

		// Confirmation Message
		cout << ptrCar->getMake() << " " << ptrCar->getModel() << " was written to the file!" << endl;
	}
}
