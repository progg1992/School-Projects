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
string determineChildType(Vehicle* ptrVehicle);

/// Entry point to the application
int main()
{
	// Create Car Objects
	const int NUM_CARS = 4;
	Vehicle* vehicles[NUM_CARS];
	vehicles[0] = new Car("X2345678901234567", "Ford", "Mustang", 2010, 8500.0, 2, false, Engine(8, 315));
	vehicles[1] = new SUV("S2345678901234567", "Honda", "Pilot", 2015, 15000.0, 8, 47.7f, Engine(6, 250));
	vehicles[2]= new GasCar("G2345678901234567", "Chevy", "Corvette", 2007, 16000.0, 2, false, 18, 19, Engine(8, 400));
	vehicles[3] = new ElectricCar("E2345678901234567", "Tesla", "Model 3", 2018, 40000.0, 4, false, 75, 240, 136, Engine(0, 271));

	// Check the Size
	cout << "Size of Car object: " << sizeof(vehicles[0]) << endl;
	cout << "Size of pointer to Car object: " << sizeof(*vehicles[0]) << endl;
	cout << endl;


	// Delete File if it Exists
	remove("data.txt");

	// Save to file
	for (int i = 0; i < NUM_CARS; i++)
	{
		saveToFile(vehicles[i]);
	}

	for (int i = 0; i < NUM_CARS; i++)
	{
		delete vehicles[i];
	}

	// Pause
	cout << endl;
	system("pause");

	return 0;
}

void saveToFile(Vehicle* ptrVehicle)
{
	ofstream outToFile("data.txt", ios::app);

	string childType = determineChildType(ptrVehicle);

	// If File is open write to it
	if (outToFile.is_open())
	{
		outToFile << childType << ',';
		outToFile << ptrVehicle->getVin() << ',' << ptrVehicle->getMake() << ','
			<< ptrVehicle->getModel() << ',' << ptrVehicle->getYear() << ',' << ptrVehicle->getPrice() << ','
			<< ptrVehicle->getMotor().getNumCylinders() << ',' << ptrVehicle->getMotor().getHorsePower() << endl;

		if (childType == "SUV")
		{
			SUV* s1 = dynamic_cast<SUV*>(ptrVehicle);
			outToFile << ',' << s1->getNumSeats()
				<< ',' << s1->getCargoSize();
		}

		if (childType == "Car")
		{
			Car* c1 = dynamic_cast<Car*>(ptrVehicle);
			outToFile << ',' << c1->getNumDoors()
				<< ',' << c1->getHatchback();
		}

		if (childType == "ElectricCar")
		{
			ElectricCar* e1 = dynamic_cast<ElectricCar*>(ptrVehicle);
			outToFile << ',' << e1->getBatterySize()
				<< ',' << e1->getRange() << ',' << e1->getMpgE();
		}

		if (childType == "GasCar")
		{
			GasCar* g1 = dynamic_cast<GasCar*>(ptrVehicle);
			outToFile << ',' << g1->getTankSize() << ',' << g1->getMPG();
		}

		outToFile << endl;

		// Close File
		outToFile.close();

		// Confirmation Message
		cout << ptrVehicle->getMake() << " " << ptrVehicle->getModel() << " was written to the file!" << endl;
	}
}

string determineChildType(Vehicle* ptrVehicle)
{
	ElectricCar* e1 = dynamic_cast<ElectricCar*>(ptrVehicle);
	if (e1 != nullptr)
		return "ElectricCar";

	GasCar* g1 = dynamic_cast<GasCar*>(ptrVehicle);
	if (g1 != nullptr)
		return "GasCar";

	Car* c1 = dynamic_cast<Car*>(ptrVehicle);
	if (c1 != nullptr)
		return "Car";

	SUV* s1 = dynamic_cast<SUV*>(ptrVehicle);
	if (s1 != nullptr)
		return "SUV";

	return "Error";
}
