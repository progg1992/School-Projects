#pragma once
#include <string>
using namespace std;

class Glasses
{
private:
	// Atributes
	string color;
	float prescription;
	
public:
	// Constructors and Destructor
	Glasses(void);
	Glasses(string color, float prescription);
	~Glasses(void);

	// Behaviors
	string toString(void);

	// Accessors and Mutators
	string getColor();
	void setColor(string color);

	float getPrescription(void);
	void setPrescription(float prescription);
};

