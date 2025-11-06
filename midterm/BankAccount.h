#pragma once
#ifndef BANKACCOUNT_H 
#define BANKACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
private:
    double balance;
    

public:
    vector<string> transactions;
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount);

    void makePurchase(string item, double cost);
    
    double checkBalance();

    double displayBalance() const;

    void getTransactions();
    void rewriteTransactions(vector<string>* transactions);

    void saveTransaction(string type, double amount);
};

#endif // !BANKACCOUNT_H

