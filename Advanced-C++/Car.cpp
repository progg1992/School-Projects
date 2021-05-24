#include "Car.h"

Car::Car()
{
	vin = "Unknown";
	make = "Unknown";
	model = "Unknown";
	year = 0;
	price = 0.0;
	numDoors = 0;
	hatchback = false;
}

Car::Car(string vin, string make, string model, short year, double price, short numDoors, bool hatchback)
{
	setVin(vin);
	setMake(make);
	setModel(model);
	setYear(year);
	setPrice(price);
	setNumDoors(numDoors);
	setHatchback(hatchback);
}

Car::~Car()
{
}

string Car::toString()
{
	return "Vin: " + vin + ", make: " + make + ", model: " + model + ", year: " + to_string(year) + ", price: " + to_string(price) + ", numDoors: " + to_string(numDoors) + ", hatchback: " + to_string(hatchback);
}

double Car::discountPrice(float discountPercent)
{
	double newPrice = price - (price * discountPercent);
	return newPrice;
}

string Car::getVin()
{
	return vin;
}

void Car::setVin(string vin)
{
	if (vin.length() > 0)
		this->vin = vin;
	else
		this->vin = "Unknown";
}

string Car::getMake()
{
	return make;
}

void Car::setMake(string make)
{
	if (make.length() > 0)
		this->make = make;
	else
		this->make = "Unknown";
}

string Car::getModel()
{
	return model;
}

void Car::setModel(string model)
{
	if (model.length() > 0)
		this->model = model;
	else
		this->model = "Unknown";
}

short Car::getYear()
{
	return year;
}

void Car::setYear(short year)
{
	if (year > 1980)
		this->year = year;
	else
		this->year = 0;
}

double Car::getPrice()
{
	return price;
}

void Car::setPrice(double price)
{
	if (price > 0 && price < 1000000)
		this->price = price;
	else
		this->price = 0.0;
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