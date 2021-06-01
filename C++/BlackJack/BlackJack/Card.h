#pragma once

#include <ctime>
#include <stdlib.h>
#include <string>
using namespace std;

class Card
{
private:
	// Attributes
	char suit;
	char face;
	short value;

	// Class wide variable
	static bool randomizerSeeded;


public:
	Card();
	~Card();

	// Behaviors
	string toString();
	bool flipAceToOne();
	
	// Accessors and Mutators
	inline char getSuit() { return suit; }
	inline char getFace() { return face; }
	inline short getValue() { return value; }
};

