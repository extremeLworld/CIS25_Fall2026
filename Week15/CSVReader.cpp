#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "CSVReader.h"

using namespace std;

void Display::displayData(int index) {
	cout << title.readVector(index) << " / Rated: (" << rating.readVector(index) << ") / Score:" << mean_score.readVector(index)
		<< " / Rank: " << rank.readVector(index) << " / Episodes: " << num_episodes.readVector(index) << endl;
}

string Column::readVector(int index) {
	return values[index];
}

void Column::addToColumn(string value) {
	values.push_back(value);
	//cout << values.back() << endl;
}

int Column::getSize() {
	return values.size();
}