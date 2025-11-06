#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BankAccount.h"
using namespace std;

double BankAccount::displayBalance() const {
    return balance;
}

double BankAccount::checkBalance() {
    balance = stof(transactions[0]);
    return balance;
}

void BankAccount::deposit(double amount) {
    balance += amount;
    cout << "Deposited " << amount << " for a total balance of " << balance << endl;
    saveTransaction("Deposit", amount);
}

void BankAccount::makePurchase(string item, double cost) {
    if (cost > balance) {
        cout << "Insufficient funds for " << item << endl;
    }
    else {
        balance -= cost;
        transactions[0] = to_string(balance);
        cout << "Purchased " << item << endl;
        saveTransaction("Purchase - " + item, cost);
    }
}

void BankAccount::getTransactions() {
    ifstream file("transactions.txt", ios::binary);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            transactions.push_back(line);
        }
        file.close();
    }
}
//this is literally only to edit the balance value at the top
void BankAccount::rewriteTransactions(vector<string>* transactions) {
    
    
    ofstream file("transactions.txt", ios::out);   
    
    if (file.is_open()) {
        file.clear();
        for (const auto& str : *transactions) {
            file << str << endl;
        }
    }

    for (const auto& str : *transactions) {
        cout << str << endl;
    }
}

void BankAccount::saveTransaction(string type, double amount) {
    ofstream file("transactions.txt", ios::app);
    if (file.is_open()) {
        string easy;
        easy = type + ": $" + to_string(amount);
        file << easy << endl;
        transactions.push_back(easy);
        file.close();
    }
}