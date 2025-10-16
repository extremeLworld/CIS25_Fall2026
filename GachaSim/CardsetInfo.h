#pragma once
#ifndef CARDSETINFO_H
#define CARDSETINFO_H

#include <vector>
#include <string>

using namespace std;

struct Card {

	int id; //assuming we want different sets in the collection, perhaps it'd be better to keep the id as a string?
	string rarity;
	string name;

};

class Cardset {
public:
	vector<Card> cards;
	string setName;

	float ssrRate;
	float srRate;
	float rRate;
	float cRate;

	//Cardset(string& setName, float ssr, float sr, float rr, float cr);
};

#endif