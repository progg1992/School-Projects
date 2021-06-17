#pragma once

#include "Car.h"

class GasCar: public Car
{
private:
	// Attributes
	float tankSize;
	short mpg;

public:
	// Constructor and Destructor
	GasCar();
	GasCar(string vin, string make, string model, short year, double price, short numDoors, bool hatchback, float tankSize, short mpg, Engine motor);
	virtual~GasCar();

	// Behaviors
	string toString();

	// Accessors and Mutators
	float getTankSize();
	void setTankSize(float tankSize);

	short getMPG();
	void setMPG(short mpg);
};

