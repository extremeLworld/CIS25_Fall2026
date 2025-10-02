// Week1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "programheader.h"
using namespace std;


void showMenu() {
	cout << "1. Add\n2. Subtract\n3. Exit\n";
}
int main() {
	int option;
	int a, b;
	do {
		showMenu();
		cin >> option;

		switch (option) {
			case 1:
				cout << "Enter in two values to add them.\n";
				cin >> a >> b;
				cout << "Result is " + to_string(add(a, b)) + ".\n";
				break;
			case 2:
				cout << "Enter in two values to subtract them.\n";
				cin >> a >> b;
				cout << "The result is " + to_string(subtract(a, b)) + ".\n";
				break;
			default:
				cout << "Exiting menu.";
				return 0;
		}
	} while (option != 3);
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
