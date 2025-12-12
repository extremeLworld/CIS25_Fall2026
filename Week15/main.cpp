#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "CSVReader.h"
using namespace std;

void readCSV(Display& display) {
	ifstream ifile;
	string line;
	string value;
	int location;
	string columns[15];


	ifile.open("animes.csv");
	getline(ifile, line);

	//find the comma and make the columns	
	for (int i = 0; i < 15; i++) {
		location = line.find(',');
		columns[i] = line.substr(0, location);
		line = line.substr(location + 1, line.length());
	}

	while (getline(ifile, line)) {

		for (int i = 0; i < 19; i++) {
			location = line.find(',');
			value = line.substr(0, location);
			switch (i) {
			case 1:
				display.title.addToColumn(value);
				line = line.substr(location + 1, line.length());
				break;
			case 7:
				display.rating.addToColumn(value);
				line = line.substr(location + 1, line.length());
				break;
			case 8:
				display.mean_score.addToColumn(value);
				line = line.substr(location + 1, line.length());
				break;
			case 9:
				display.rank.addToColumn(value);
				line = line.substr(location + 1, line.length());
				break;
			case 15:
				display.num_episodes.addToColumn(value);
				line = line.substr(location + 1, line.length());
				break;
			default:
				line = line.substr(location + 1, line.length());
				break;
			}

			
		}
		
	}

	ifile.close();
}

int main() {
	Display display;

	readCSV(display);
	for (int i = 0; i < 20; i++) {
		display.displayData(i);
	}
	//use display.[whatever column cause they should all be the same size].getSize() if you want to display everything,
	//but the csv doesn't have every value formatted properly so it might look odd



}