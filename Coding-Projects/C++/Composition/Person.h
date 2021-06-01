#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Glasses.h"
using namespace std;

class Person
{
private:
	// Attributes
	string name;
	string ssn;
	Glasses myGlasses;

public:
	// Constructors and Destructor
	Person();
	Person(string name, string ssn, Glasses currentGlasses);
	~Person();

	// Behaviors
	string toString(void);
	string writeToFile(void);
	string readFromFile(void);

	// Accessors and Mutators
	string getName(void);
	void setName(string name);

	string getSSN(void);
	void setSSN(string ssn);

	Glasses getMyGlasses(void);
	void setMyGlasses(Glasses currentGlasses);
};

