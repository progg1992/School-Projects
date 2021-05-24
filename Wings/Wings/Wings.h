#pragma once
#include <string>
#include <iostream>
using namespace std;

class Wings
{
private:
	// attributes
	string flavor;
	short numPieces;

public:
	// constructors
	Wings(string flavor = "unknown", short  numberOfPieces = 0);
	~Wings(void);

	// behaviors
	Wings operator+(const Wings secondWings) const;
	Wings operator-(const Wings secondWings) const;
	Wings operator-(void);
	Wings& operator++(void);
	Wings operator++(int);
	Wings& operator=(const Wings& equalWings);

	friend istream& operator>>(istream& is, Wings& obj);
	friend ostream& operator<<(ostream& os, Wings& obj);

	// accessors and mutators
	string  getFlavor(void);
	void setFlavor(string flavor);

	short getNumberOfPieces(void);
	void setNumberOfPieces(short numberOfPieces);
};
