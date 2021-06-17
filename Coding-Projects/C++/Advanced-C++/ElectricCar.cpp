#include "ElectricCar.h"

ElectricCar::ElectricCar() {
	batterySize = 0.0f;
	range = 0;
	mpgE = 0;
}

ElectricCar::ElectricCar(string vin, string make, string model, short year, double price, short numDoors, bool hatchback, float batterySize, short range, short mpgE, Engine motor) : Car(vin, make, model, year, price, numDoors, hatchback, motor) {
	setBatterySize(batterySize);
	setRange(range);
	setMpgE(mpgE);
}

ElectricCar::~ElectricCar() {}

string ElectricCar::toString() {
	return Car::toString() = ", batterySize: " + to_string(batterySize) + ", range: " + to_string(range) + ", mpgE: " + to_string(mpgE);
}

float ElectricCar::getBatterySize() {
	return batterySize;
}

void ElectricCar::setBatterySize(float batterySize) {
	if (batterySize > 0.0f)
		this->batterySize = batterySize;
	else
		this->batterySize = 0.0f;
}

short ElectricCar::getRange() {
	return range;
}

void ElectricCar::setRange(short range) {
	if (range > 0)
		this->range = range;
	else
		this->range = 0;
}

short ElectricCar::getMpgE() {
	return mpgE;
}

void ElectricCar::setMpgE(short mpgE) {
	if (mpgE > 0)
		this->mpgE = mpgE;
	else
		this->mpgE = 0;
}