#pragma once

#include <string>
#include "Vehicle.h"
using namespace std;

class Car: public Vehicle
{
private:
	// Attributes
	short numDoors;
	bool hatchback;

public:
	// Constructors and Destructor
	Car();
	Car(string vin, string make, string model, short year, double price, short numDoors, bool hatchback, Engine motor);
	~Car();

	// Behaviors
	string toString();

	// Accessors and Mutators
	short getNumDoors();
	void setNumDoors(short numDoors);

	bool getHatchback();
	void setHatchback(bool isHatchback);
};

