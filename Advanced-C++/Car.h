#pragma once

#include <string>
using namespace std;

class Car
{
private:
	// Attributes
	string vin;
	string make;
	string model;
	short year;
	double price;
	short numDoors;
	bool hatchback;

public:
	// Constructor and Destructor
	Car();
	Car(string vin, string make, string model, short year, double price, short numDoors, bool hatchback);
	~Car();

	// Behaviors
	string toString();
	double discountPrice(float discountPercent);

	// Accessors and Mutators
	string getVin();
	void setVin(string vin);

	string getMake();
	void setMake(string make);

	string getModel();
	void setModel(string model);

	short getYear();
	void setYear(short year);

	double getPrice();
	void setPrice(double price);

	short getNumDoors();
	void setNumDoors(short numDoors);

	bool getHatchback();
	void setHatchback(bool isHatchback);
};

