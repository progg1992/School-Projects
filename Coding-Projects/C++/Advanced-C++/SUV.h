#pragma once

#include "Vehicle.h"

class SUV: public Vehicle
{
private:
	// Attributes
	short numSeats;
	float cargoSize;

public:
	// Constructors and Destructor
	SUV();
	SUV(string vin, string make, string model, short year, double price, short numSeats, float cargoSize, Engine motor);
	virtual~SUV();

	// Behaviors
	string toString();

	// Accessors and Mutators
	short getNumSeats();
	void setNumSeats(short numSeats);

	float getCargoSize();
	void setCargoSize(float cargoSize);
};

