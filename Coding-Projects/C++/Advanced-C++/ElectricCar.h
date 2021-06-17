#pragma once

#include "Car.h"

class ElectricCar: public Car
{
private:
	// Attributes
	float batterySize;
	short range;
	short mpgE;

public:
	// Constructors and Destructor
	ElectricCar();
	ElectricCar(string vin, string make, string model, short year, double price, short numDoors, bool hatchback, float batterySize, short range, short mpgE, Engine motor);
	virtual~ElectricCar();

	// Behaviors
	string toString();

	// Accessors and Mutators
	float getBatterySize();
	void setBatterySize(float batterySize);

	short getRange();
	void setRange(short range);

	short getMpgE();
	void setMpgE(short mpgE);
};

