// Week1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
public:
	string name;
	int quantity;
    
    void saveToFile() {
        ofstream out("items.txt");
        if (out.is_open()) {
            out << name << "," << quantity << endl;
            out.close();
            cout << "Item saved to file." << endl;
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }
    }
    void loadFromFile() {
        ifstream in("items.txt");
        if (in.is_open()) {
            string line;
            while (getline(in, line)) {
                cout << "File content: " << line << endl;
            }
            in.close();
        }
        else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};

int main() {
    Item tool;
    
    cout << "What is the name of the tool?\n";
    cin >> tool.name;
    cout << "How many of the tool?\n";
    cin >> tool.quantity;


    tool.saveToFile();
    tool.loadFromFile();

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
