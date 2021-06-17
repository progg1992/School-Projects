#include "Car.h"

Car::Car(): Vehicle()
{
	numDoors = 0;
	hatchback = false;
}

Car::Car(string vin, string make, string model, short year, double price, short numDoors, bool hatchback, Engine motor): Vehicle(vin, make, model, year, price, motor)
{
	setNumDoors(numDoors);
	setHatchback(hatchback);
}

Car::~Car() {}

string Car::toString()
{
	return Vehicle::toString() + ", numDoors: " + to_string(numDoors) + ", hatchback: " + to_string(hatchback);
}

short Car::getNumDoors()
{
	return numDoors;
}

void Car::setNumDoors(short numDoors)
{
	if (numDoors > 0 && numDoors < 5)
		this->numDoors = numDoors;
	else
		this->numDoors = 0;
}

bool Car::getHatchback()
{
	return hatchback;
}

void Car::setHatchback(bool isHatchback)
{
	this->hatchback = isHatchback;
}