#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "BankAccount.h"
using namespace std;

BankAccount myAccount;

int main() {
    myAccount.getTransactions();
    cout << "Current balance is: " << myAccount.checkBalance() << endl;

    myAccount.deposit(5.00);
    myAccount.makePurchase("Coffee", 4.50);
    myAccount.makePurchase("Book", 25.00);
    cout << "Current Balance: $" << myAccount.displayBalance() << endl;

    myAccount.rewriteTransactions(&myAccount.transactions);

    return 0;
}



