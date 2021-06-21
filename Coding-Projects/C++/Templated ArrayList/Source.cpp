#include <iostream>
#include <string>
#include <conio.h>
#include "ArrayList.h"
using namespace std;

/// Entry Point To the Application
int main(void)
{
	// Check for memory leak
#if defined(DEBUG) | defined(DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// Create an int ArrayList
	ArrayList<int> intList;
	intList.add(27);
	intList.add(13);
	intList.add(42);
	intList.add(31);
	intList.add(22);
	intList.add(19);

	for (int i = 0; i < intList.getCount(); i++)
	{
		cout << intList.get(i) << ", ";
	}

	cout << "\n" << endl;
	cout << "Count: " << intList.getCount() << endl;
	cout << "Capacity: " << intList.getCapacity() << endl;

	cout << "\n\n" << endl;

	// Create a string ArrayList
	ArrayList<string> strList;
	strList.add("Brendan");
	strList.add("Maria");
	strList.add("Ivan");
	strList.add("Nathan");

	// Display list data
	for (int i = 0; i < strList.getCount(); i++)
	{
		cout << strList.get(i) << ", ";
	}
	
	cout << "\n" << endl;
	cout << "Count: " << strList.getCount() << endl;
	cout << "Capacity: " << strList.getCapacity() << endl;

	// Pause
	cout << "\nPress any Key to continue...";
	cin.sync();
	_getch();

	return 0;
}