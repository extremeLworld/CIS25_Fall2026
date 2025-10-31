#include <iostream>
#include <fstream>
#include <string>
#include <"BankAccount.h">
using namespace std;



int main() {
    BankAccount myAccount;

    myAccount.deposit(100.00);
    myAccount.makePurchase("Coffee", 4.50);
    myAccount.makePurchase("Book", 25.00);
    myAccount.displayBalance();

    return 0;
}



