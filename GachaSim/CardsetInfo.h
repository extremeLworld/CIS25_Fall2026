#pragma once
#ifndef CARDSETINFO_H
#define CARDSETINFO_H

#include <vector>
#include <string>

using namespace std;

enum class Rarity { //sort the rarities with an enum
	SSR,
	SR,
	R,
	C,
	Failsafe
};

struct Card {

	int id; //assuming we want different sets in the collection, perhaps it'd be better to keep the id as a string?
	Rarity rarity;
	string name;

};

class Cardset {
private:
	float ssrRate;
	float srRate;
	float rRate;
	float cRate;
public:
	vector<Card> cards;
	string setName; //for some reason i can't pass the string through constructor so ill just leave it public	

	Cardset(float ssr, float sr, float rr, float cr); //constructor
};

class Pack {
private:
	int amountOfCards;
	int price;
public:
	Pack(int numberOfCards, int money);
	int getPrice() const { return price; }
	void rollCards(Cardset& cardset);
};

//non class functions
Rarity stringToRarity(string& rStr);
string rarityToString(Rarity r);

#endif