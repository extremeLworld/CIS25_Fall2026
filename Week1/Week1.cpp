// Week1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Item {
    int id;
    string name;
};

int loadFromFile(Item* inventory, int maxNum) { //i know this works
    int count = 0;

    //cout << "maxNum is " << maxNum;
    ifstream in("items.txt");
    if (in.is_open()) {
        string line;
        while (getline(in, line) && count < maxNum) {
            inventory[count].id = count + 1;
            inventory[count].name = line;

            count++;
        }
        in.close();
    }
    else {
        cout << "Unable to open file for reading." << endl;
    }

    return count;
}

string binarySearcher(Item* inventory, int size, int id) {

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // should be 50 if we're looking at 100

        if (id == inventory[mid].id) {
            return inventory[mid].name;
        }
        else if (id > inventory[mid].id) {
            left = mid + 1; //search the right side
        }
        else {
            right = mid - 1; //search the left side
        }
    }
    return "";
}

int main() {
    Item* inventory = new Item[100];
    int size = loadFromFile(inventory, 100);
    char choice;

    //int arrSize = sizeof(inventory) / sizeof(inventory[0]); //i guess this thing doesn't work with what i wanna do
    int userId;

    string searchedItem;
    

    do {
        cout << "Which id do you want to look at? ";
        cin >> userId;

        searchedItem = binarySearcher(inventory, size, userId);

        if (searchedItem != "") {
            cout << "The item at " << userId << " is " << searchedItem << ".\n";
        }
        else {
            cout << "Item not found.";
        }
        cout << "Keep searching? (choose y for yes) ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    delete[] inventory;
    cout << "Thanks!";

    return 0;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
