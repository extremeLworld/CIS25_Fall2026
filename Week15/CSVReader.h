#pragma once
#ifndef CSVREADER_H
#define CSVREADER_H


#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Column {
private:
	vector<string> values;
public:
	string readVector(int index);
	void addToColumn(string value);
	int getSize();
	//print the value from the function
};

class Display {	
public:	
	Column title, mean_score, rank, num_episodes, rating;
	void displayData(int index);
};

#endif // !CSVREADER_H
