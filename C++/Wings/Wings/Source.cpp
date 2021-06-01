/*
Pierce Rogg
CIS 247C
Wings Application
5/23/2021
*/

// Required Libraries
#include <iostream>
#include <conio.h>
#include <string>
#include "Wings.h"
using namespace std;

/// Entry point to the application
int main()
{
	// create 2 Wings
	Wings w1("Lemon Pepper", 6);
	Wings w2("BBQ", 6);

	Wings w3 = w1 + w2;

	cout << "Combined wings: " << w3.getFlavor() << ", " << w3.getNumberOfPieces() << endl;

	Wings w4 = w3 - w2;

	cout << "Subtracted Wings: " << w4.getFlavor() << ", " << w4.getNumberOfPieces() << endl;

	Wings w5 = -w4;

	cout << "Negated Wings: " << w4.getFlavor() << ", " << w4.getNumberOfPieces() << endl;

	w5 = -w5;
	++w5;

	cout << "Pre-incremented Wings: " << w5.getFlavor() << ", " << w5.getNumberOfPieces() << endl;

	w5++;

	cout << "Post-incremented Wings: " << w5.getFlavor() << ", " << w5.getNumberOfPieces() << endl;

	Wings w6 = w5;

	cout << "Equal Wings: " << w6.getFlavor() << ", " << w6.getNumberOfPieces() << endl;

	Wings w7;
	cin >> w7;

	cout << "Input stream Wings: " << w7.getFlavor() << ", " << w7.getNumberOfPieces() << endl;

	cout << "Output stream Wings: " << w7 << endl;

	// Pause
	cout << "\nPress any key to continue...";
	_getch();
	return 0;
}
