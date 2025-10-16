#include <iostream>
#include <fstream>
#include <sstream>
#include <"CardsetInfo.h">

using namespace std;

void loadSet(string setName, Cardset cardset) { // this will load the card values from a text file
	ifstream in(setName);

	if (in.is_open()) {
		string line;

		while (getline(in, line)) {
			stringstream ss(line); //getting the string from the txt file so we can use it
			string id, rarity, name;

			if (getline(ss, id, ',') && getline(ss, rarity, ',') && getline(ss, name, ',')) { //get the format of the txt file
				Card temp; //defining temp to make it easier on my eyes to put stuff in the cardset vector
				temp.id = stoi(id);
				temp.rarity = rarity;
				temp.name = name;

				cardset.cards.push_back(temp);
			}

			in.close();
		}
	}
	else {
		cout << "Could not open set file.";
	}
}

int main() {
	Cardset tbhxCardset;
	tbhxCardset.name = "TBHX";

	loadSet("Set_TBHX.txt", tbhxCardset);

	return 0;
}