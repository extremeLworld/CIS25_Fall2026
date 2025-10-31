#pragma once
#ifndef BANKACCOUNT_H 
#define BANKACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount);

    void makePurchase(string item, double cost);

    void displayBalance();

    void saveTransaction(string type, double amount);
};

#endif // !BANKACCOUNT_H

