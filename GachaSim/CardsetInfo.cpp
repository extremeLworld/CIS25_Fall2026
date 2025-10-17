#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <time.h>
#include "CardsetInfo.h"

using namespace std;

//cardset constructor
Cardset::Cardset(float ssr, float sr, float rr, float cr): ssrRate(ssr), srRate(sr), rRate(rr), cRate(cr) { }

// let's try to make sure we have the cards working first before we do the pulls
Pack::Pack(int numberOfCards, int money) {
	amountOfCards = numberOfCards;
	price = money;
}
void Pack::rollCards(Cardset& cardset) {
	//for now, let's make sure the cards roll and print out properly before we add it to the user's collection
	static mt19937 rng(random_device{}()); //this apparently has better random than just srand


	cout << "You rolled:\n";
	for (int i = 0; i < amountOfCards; i++) {
		int rolledNumber = rng() % cardset.cards.size();
		cout << cardset.cards[rolledNumber].id << " / " << rarityToString(cardset.cards[rolledNumber].rarity) << " / " << cardset.cards[rolledNumber].name << "\n";
	}
}

Rarity stringToRarity(string& rStr) { //converts the string from the txt file to an enum
	if (rStr == "SSR") return Rarity::SSR;
	if (rStr == "SR") return Rarity::SR;
	if (rStr == "R") return Rarity::R;
	if (rStr == "C") return Rarity::C;
	else return Rarity::Failsafe;
}

string rarityToString(Rarity r) { //convert rarity back to string so it can be printed :(
	if (r == Rarity::SSR) return "SSR";
	if (r == Rarity::SR) return "SR";
	if (r == Rarity::R) return "R";
	if (r == Rarity::C) return "C";
	else return "Failsafe";
}