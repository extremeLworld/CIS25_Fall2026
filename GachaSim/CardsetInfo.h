#pragma once
#ifndef CARDSETINFO_H
#define CARDSETINFO_H

#include <vector>


struct Card {
	string id; //assuming we want different sets in the collection, perhaps it'd be better to keep the id as a string?
	string rarity;
	string name;

};

class Cardset {
	vector<Card> cards;
	string setName;

	//assign rarity values here
	float ssrRate = 0.05;
	float srRate = 0.1;
	float rRate = 0.25;
	float cRate = 0.5;
};

#endif