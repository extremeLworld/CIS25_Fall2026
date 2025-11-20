#include <string>
#include "CardsetInfo.h"
#include "Inventory.h"

using namespace std;

string Inventory::binarySearcher(int size, int id) {

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