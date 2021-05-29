#include "Glasses.h"

Glasses::Glasses()
{
	color = "unknown";
	prescription = 0.0f;
}

Glasses::Glasses(string color, float prescription)
{
	setColor(color);
	setPrescription(prescription);
}

Glasses::~Glasses(void)
{
}

// Behaviors
string Glasses::toString(void)
{
	string strPrescription = to_string(prescription);
	return "Color: " + color + " Prescription: " + strPrescription;
}

// Accessors and Mutators
string Glasses::getColor(void)
{
	return color;
}

void Glasses::setColor(string color)
{
	if (color.length() > 0)
		this->color = color;
	else
		this->color = "unknown";
}

float Glasses::getPrescription(void)
{
	return prescription;
}

void Glasses::setPrescription(float prescription)
{
	if (prescription > 0.0f)
		this->prescription = prescription;
	else
		this->prescription = 0.0f;
}