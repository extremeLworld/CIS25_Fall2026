#include <iostream>
#include <string>
#include "InventoryManagement.h"

using namespace std;

void searchInventory(Item inventory[], int size, const string& query) {
	bool found = false;
	for (int i = 0; i < size; i++) {
		
		if (inventory[i].name.find(query) != string::npos) {
			cout << "Found " << inventory[i].name << " / Amount: " << inventory[i].quantity << "\n";
			found = true;
			break;
		}
		else {
			found = false;
		}
	}

	if (found == false) {
		cout << "Not found.\n";
	}
}

int main(){
	Item inventory[5];
	string itemname;
	int amount;

	int option;

	for (int i = 0; i < 5; i++) {
		cout << "Enter an item name: ";
		cin >> itemname;
		cout << "Enter the amount of that item: ";
		cin >> amount;

		inventory[i].name = itemname;
		inventory[i].quantity = amount;
	}

	do {
		cout << "Select an option: \n" << "1. Search for an entry\n" << "2. Display all entries\n" << "3. Exit\n";
		cin >> option;
		switch (option) {
		case 1:
			cout << "What would you like to search for? ";
			cin >> itemname;

			searchInventory(inventory, 5, itemname);

			break;
		case 2:
			for (int i = 0; i < 5; i++) {
				cout << inventory[i].name << " / Amount: " << inventory[i].quantity << "\n";
			}
			break;
		default:
			return 0;
		}
	} while (option != 3);

	delete(inventory);

	return 0;
}