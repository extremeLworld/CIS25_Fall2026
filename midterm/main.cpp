#include <iostream>
#include <fstream>
#include <string>
#include "BankAccount.h"
using namespace std;

BankAccount myAccount;

int main() {
    

    myAccount.deposit(30.00);
    myAccount.makePurchase("Coffee", 4.50);
    myAccount.makePurchase("Book", 25.00);
    myAccount.displayBalance();

    return 0;
}



