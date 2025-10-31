#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "CardsetInfo.h"

using namespace std;

void loadSet(string setName, Cardset& cardset) { // this will load the card values from a text file, also use the & so it references the actual variable
	ifstream in(setName);

	if (in.is_open()) {
		string line;

		while (getline(in, line)) {
			stringstream ss(line); //getting the string from the txt file so we can use it
			string id, rarity, name;

			if (getline(ss, id, ',') && getline(ss, rarity, ',') && getline(ss, name, ',')) { //get the format of the txt file
				Card temp; //defining temp to make it easier on my eyes to put stuff in the cardset vector
				temp.id = stoi(id);
				temp.rarity = stringToRarity(rarity);
				temp.name = name;

				cardset.cards.push_back(temp);
				//cout << cardset.cards.back().id << " / " << cardset.cards.back().rarity << " / " << cardset.cards.back().name << "\n"; //debug checkin line
			}
			
		}
		in.close();
	}
	else {
		cout << "Could not open set file.";
	}
}



int main() {
	//set up part
	Cardset tbhxCardset(0.1, 0.15, 0.25, 0.5); //suggested that the rates equal to 1 for readability
	tbhxCardset.setName = "TBHX";
	Pack tbhxPack(5, 10);

	loadSet("Set_TBHX.txt", tbhxCardset);

	int spentMoney = 0;
	int option;

	//the menu part :(
	do {
		cout << "Menu Options: \n1. Roll for cards\n2. View Collection\n3. Exit\n";
		cin >> option;
		switch (option) {
			case 1:
				tbhxPack.rollCards(tbhxCardset);
				spentMoney += tbhxPack.getPrice();
				cout << "You have spent $" << spentMoney << " so far.\n";
			
				char rollMenuOption;				
				
				cout << "Roll again? (y for yes)\n";
				cin >> rollMenuOption;

				while (rollMenuOption == 'y') {
					tbhxPack.rollCards(tbhxCardset);
					spentMoney += tbhxPack.getPrice();
					cout << "You have spent $" << spentMoney << " so far.\n";
					//cout << "for loop happened\n";

					cout << "Roll again? (y for yes)\n";
					cin >> rollMenuOption;
				}

				break;
			case 2:
				cout << "Viewing collection not available yet :p, loop back";
				break;
			default:
				cout << "Exiting program.\n";
				return 0;
		}
	} while (option != 3);


	return 0;
}