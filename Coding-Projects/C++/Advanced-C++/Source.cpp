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
#include "Vehicle.h"
#include "Car.h"
#include "SUV.h"
#include "GasCar.h"
#include "ElectricCar.h"
using namespace std;

// Prototypes
void saveToFile(Vehicle* ptrVehicle);
void saveToFile(Car* ptrCar);
void saveToFile(SUV* ptrSUV);
void saveToFile(GasCar* ptrGasCar);
void saveToFile(ElectricCar* ptrElectricCar);

/// Entry point to the application
int main()
{
	// Create Car Objects8, 315
	Vehicle veh1("V2345678901234567", "General", "General", 2000, 10000.0, Engine(4, 100));
	Car car1("X2345678901234567", "Ford", "Mustang", 2010, 8500.0, 2, false, Engine(8, 315));
	SUV suv1("S2345678901234567", "Honda", "Pilot", 2015, 15000.0, 8, 47.7f, Engine(6, 250));
	GasCar gas1("G2345678901234567", "Chevy", "Corvette", 2007, 16000.0, 2, false, 18, 19, Engine(8, 400));
	ElectricCar electric1("E2345678901234567", "Tesla", "Model 3", 2018, 40000.0, 4, false, 75, 240, 136, Engine(0, 271));

	// Check the Size
	cout << "Size of Car object: " << sizeof(car1) << endl;
	cout << "Size of pointer to Car object: " << sizeof(&car1) << endl;
	cout << endl;


	// Delete File if it Exists
	remove("data.txt");

	// Save to file
	saveToFile(&veh1);
	saveToFile(&car1);
	saveToFile(&suv1);
	saveToFile(&gas1);
	saveToFile(&electric1);

	// Pause
	cout << endl;
	system("pause");

	return 0;
}

void saveToFile(ElectricCar* ptrElectricCar)
{
	ofstream outToFile("data.txt", ios::app);

	// If File is open write to it
	if (outToFile.is_open())
	{
		outToFile << ptrElectricCar->getVin() << ',' << ptrElectricCar->getMake() << ',' 
			<< ptrElectricCar->getModel() << ',' << ptrElectricCar->getYear() << ',' << ptrElectricCar->getPrice() << ',' 
			<< ptrElectricCar->getNumDoors() << ',' << ptrElectricCar->getHatchback() << ',' 
			<< ptrElectricCar->getBatterySize() << ',' << ptrElectricCar->getRange() << ',' << ptrElectricCar->getMpgE() << ','
			<< ptrElectricCar->getMotor().getNumCylinders() << ',' << ptrElectricCar->getMotor().getHorsePower() << endl;

		// Close File
		outToFile.close();

		// Confirmation Message
		cout << ptrElectricCar->getMake() << " " << ptrElectricCar->getModel() << " was written to the file!" << endl;
	}
}

void saveToFile(GasCar* ptrGasCar)
{
	ofstream outToFile("data.txt", ios::app);

	// If File is open write to it
	if (outToFile.is_open())
	{
		outToFile << ptrGasCar->getVin() << ',' << ptrGasCar->getMake() << ','
			<< ptrGasCar->getModel() << ',' << ptrGasCar->getYear() << ',' << ptrGasCar->getPrice() << ','
			<< ptrGasCar->getNumDoors() << ',' << ptrGasCar->getHatchback() << ','
			<< ptrGasCar->getTankSize() << ',' << ptrGasCar->getMPG() << ','
			<< ptrGasCar->getMotor().getNumCylinders() << ',' << ptrGasCar->getMotor().getHorsePower() << endl;

		// Close File
		outToFile.close();

		// Confirmation Message
		cout << ptrGasCar->getMake() << " " << ptrGasCar->getModel() << " was written to the file!" << endl;
	}
}

void saveToFile(SUV* ptrSUV)
{
	ofstream outToFile("data.txt", ios::app);

	// If File is open write to it
	if (outToFile.is_open())
	{
		outToFile << ptrSUV->getVin() << ',' << ptrSUV->getMake() << ','
			<< ptrSUV->getModel() << ',' << ptrSUV->getYear() << ',' << ptrSUV->getPrice() << ','
			<< ptrSUV->getNumSeats() << ',' << ptrSUV->getCargoSize() << ','
			<< ptrSUV->getMotor().getNumCylinders() << ',' << ptrSUV->getMotor().getHorsePower() << endl;

		// Close File
		outToFile.close();

		// Confirmation Message
		cout << ptrSUV->getMake() << " " << ptrSUV->getModel() << " was written to the file!" << endl;
	}
}

void saveToFile(Car* ptrCar)
{
	ofstream outToFile("data.txt", ios::app);

	// If File is open write to it
	if (outToFile.is_open())
	{
		outToFile << ptrCar->getVin() << ',' << ptrCar->getMake() << ','
			<< ptrCar->getModel() << ',' << ptrCar->getYear() << ',' << ptrCar->getPrice() << ','
			<< ptrCar->getNumDoors() << ',' << ptrCar->getHatchback() << ','
			<< ptrCar->getMotor().getNumCylinders() << ',' << ptrCar->getMotor().getHorsePower() << endl;

		// Close File
		outToFile.close();

		// Confirmation Message
		cout << ptrCar->getMake() << " " << ptrCar->getModel() << " was written to the file!" << endl;
	}
}

void saveToFile(Vehicle* prtVehicle)
{
	ofstream outToFile("data.txt", ios::app);

	// If File is open write to it
	if (outToFile.is_open())
	{
		outToFile << prtVehicle->getVin() << ',' << prtVehicle->getMake() << ','
			<< prtVehicle->getModel() << ',' << prtVehicle->getYear() << ',' << prtVehicle->getPrice() << ','
			<< prtVehicle->getMotor().getNumCylinders() << ',' << prtVehicle->getMotor().getHorsePower() << endl;

		// Close File
		outToFile.close();

		// Confirmation Message
		cout << prtVehicle->getMake() << " " << prtVehicle->getModel() << " was written to the file!" << endl;
	}
}