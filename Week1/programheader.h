#pragma once
#ifndef PROGRAMHEADER_H
#define PROGRAMHEADER_H



class Item {
    public:
    string name;
    int quantity;
    void saveToFile();
    void loadFromFile();

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

#endif