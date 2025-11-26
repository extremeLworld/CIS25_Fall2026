#include <iostream>
#include "Management.h"
using namespace std;

int main() {
    User user;
    Employee employee;
    InventoryManager mgr;
    
    cout << "User: ";
    user.accessLevel();

    cout << "Employee: ";
    employee.accessLevel();

    cout << "Manager: ";
    mgr.accessLevel(); // Should print: Full Inventory Management Access
    return 0;
}
