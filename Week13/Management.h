#pragma once
#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <iostream>

using namespace std;

class User {
public:
    virtual void accessLevel();
};

// Derived from User
class Employee : public User {
public:
    void accessLevel()override;
};

// Derived from Employee
class InventoryManager : public Employee {
public:
    void accessLevel() override;
};


#endif // !MANAGEMENT_H
