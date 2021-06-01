#include "Card.h"

bool Card::randomizerSeeded = false;

Card::Card()
{
	// Seed randomizer
	if (!randomizerSeeded)
	{
		srand(time(0));
		randomizerSeeded = true;
	}

	// Create Random Number for the suit
	short min = 3;
	short max = 6;
	suit = rand() % (max - min + 1) + min;

	// create a random number for card value and face
	min = 2;
	max = 14;
	short number = rand() % (max - min + 1) + min;

	if (number >= 2 && number <= 9)
	{
		value = number;
		face = number + 48;
	}

	else if (number == 10)
	{
		value = number;
		face = 'T';
	}

	else if (number == 11)
	{
		value = 10;
		face = 'J';
	}

	else if (number == 12)
	{
		value = 10;
		face = 'Q';
	}

	else if (number == 13)
	{
		value = 10;
		face = 'K';
	}

	else if (number == 14)
	{
		value = 10;
		face = 'A';
	}

	else
	{
		value = -1;
		face = 'E';
	}
}

Card::~Card()
{

}

string Card::toString()
{
	string output = "";
	output += suit;
	output += face;
	return output;
}

bool Card::flipAceToOne()
{
	if (value == 11)
	{
		value = 1;
		return true;
	}
	else
	{
		return false;
	}
}