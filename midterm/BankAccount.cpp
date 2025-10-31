#include <iostream>
#include <fstream>
#include <string>
#include "BankAccount.h"
using namespace std;

void BankAccount::displayBalance() {
    cout << "Current Balance: $" << balance << endl;
}

void BankAccount::deposit(double amount) {
    balance += amount;
    cout << "Added starting balance of " << balance << endl;
    saveTransaction("Deposit", amount);
}

void BankAccount::makePurchase(string item, double cost) {
    if (cost > balance) {
        cout << "Insufficient funds for " << item << endl;
    }
    else {
        balance -= cost;
        cout << "Purchased " << item << endl;
        saveTransaction("Purchase - " + item, cost);
    }
}

void BankAccount::saveTransaction(string type, double amount) {
    ofstream file("transactions.txt", ios::app);
    if (file.is_open()) {
        file << type << ": $" << amount << endl;
        file.close();
    }
}