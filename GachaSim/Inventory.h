#pragma once
#ifndef	INVENTORY_H
#define INVENTORY_H

#include <string>
#include "CardsetInfo.h"

using namespace std;

class Inventory {
private:
    vector<Card> inventory;

public:
    string binarySearcher(int size, int id);
    void removeDuplicates();
    //sorting functions below

};

#endif