#include "Wings.h"

// constructors
Wings::Wings(string flavor, short numberOfPieces)
{
	setFlavor(flavor);
	setNumberOfPieces(numberOfPieces);
}
Wings::~Wings(void)
{
	// no dynamic objects to destroy
}

// behaviors

// Overload Addition Operator
Wings Wings::operator+(const Wings secondWings) const
{
	Wings thirdWings;

	thirdWings.numPieces = this->numPieces + secondWings.numPieces;

	if (this->flavor != secondWings.flavor)
		thirdWings.flavor = this->flavor + " and " + secondWings.flavor;
	else
		thirdWings.flavor = this->flavor;

	return thirdWings;
}

// Overload Subtraction Operator
Wings Wings::operator-(const Wings secondWings) const
{
	Wings thirdWings;

	thirdWings.numPieces = this->numPieces - secondWings.numPieces;
	string full = this->flavor;

	short position = full.find("and", 0);
	if (position > 0)
		thirdWings.flavor = full.substr(0, position - 1);
	else
		thirdWings.flavor = this->flavor;

	return thirdWings;
}

// Overload Negation Operator
Wings Wings::operator-(void)
{
	numPieces = -numPieces;

	return *this;
}

//Overload Pre-increment Operator
Wings& Wings::operator++(void)
{
	++numPieces;

	return *this;
}

// Overload Post-increment Operator
Wings Wings::operator++(int)
{
	Wings temp = *this;

	++(*this);

	return temp;
}

// Overload Equality Operator
Wings& Wings::operator=(const Wings& equalWings)
{
	if (this != &equalWings)
	{
		this->flavor = equalWings.flavor;
		this->numPieces = equalWings.numPieces;

		return *this;
	}
}

// Overload Input stream Operator
istream& operator>>(istream& is, Wings& obj)
{
	cout << "Enter the wings flavor: ";
	getline(is, obj.flavor);
	cout << "Enter the number of wings: ";
	is >> obj.numPieces;

	return is;
}

// Overload Output stream
ostream& operator<<(ostream& os, Wings& obj)
{
	os << "Wings Flavor: " << obj.flavor << ", Number of Wings: " << obj.numPieces << endl;
	return os;
}

// accessors and mutators
string  Wings::getFlavor(void)
{
	return flavor;
}
void Wings::setFlavor(string flavor)
{
	if (flavor.length() > 0)
		this->flavor = flavor;
	else
		this->flavor = "unknown";
}

short Wings::getNumberOfPieces(void)
{
	return numPieces;
}

void Wings::setNumberOfPieces(short numberOfPieces)
{
	if (numberOfPieces > 0)
		numPieces = numberOfPieces;
	else
		numPieces = 0;
}
