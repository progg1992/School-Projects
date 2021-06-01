#pragma once
#include <string>
using namespace std;

class Engine
{
private:
	// Attributes
	short numCylinders;
	short horsePower;

public:
	// Constructors
	Engine();
	Engine(short numCylinders, short horsePower);
	~Engine();

	// Behaviors
	string toString(void);

	// Accessors and Mutators
	short getNumCylinders(void);
	void setNumCylinders(short numCylinders);

	short getHorsePower(void);
	void setHorsePower(short horsePower);
};

