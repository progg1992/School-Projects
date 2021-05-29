#include "Person.h"

Person::Person()
{
	name = "unknown";
	ssn = "unknown";
}

Person::Person(string name, string ssn, Glasses currentGlasses)
{
	setName(name);
	setSSN(ssn);
	setMyGlasses(currentGlasses);
}

Person::~Person()
{

}

// Behaviors
string Person::toString(void)
{
	return "Name: " + name + ", SSN: " + ssn + ", Glasses: [" + myGlasses.toString() + "]";
}

string Person::writeToFile(void)
{
	// Write Person to file
	string filename = name + ".txt";
	ofstream oFile(filename);

	oFile << name << endl;
	oFile << ssn << endl;
	oFile << myGlasses.getColor() << endl;
	oFile << myGlasses.getPrescription() << endl;

	oFile.close();

	// Confirmation Message
	return name + "'s data was written to the file";
}

string Person::readToFile(void)
{
	string filename = name + ".txt";
	ifstream iFile(filename);

	if (!iFile.is_open())
		return "Error. File cannot be opened. Please check if file exists.";
	else
	{
		getline(iFile, name);
		getline(iFile, ssn);

		string color = "";
		getline(iFile, color);
		float pers = 0.0f;
		iFile >> pers;
		this->setMyGlasses(Glasses(color, pers));
		iFile.ignore(1);
		iFile.close();

		return name + "'s has been read from " + filename;
	}
}

// Accessors and Mutators
string Person::getName(void)
{
	return name;
}

void Person::setName(string name)
{
	if (name.length() > 1)
		this->name = name;
	else
		this->name = "unknown";
}

string Person::getSSN(void)
{
	return ssn;
}

void Person::setSSN(string ssn)
{
	if (ssn.length() == 9 || ssn.length() == 11)
		this->ssn = ssn;
	else
		this->ssn = "unknown";
}

Glasses Person::getMyGlasses(void)
{
	return myGlasses;
}

void Person::setMyGlasses(Glasses currentGlasses)
{
	this->myGlasses = currentGlasses;
}