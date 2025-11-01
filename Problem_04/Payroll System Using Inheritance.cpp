#include <iostream>
using namespace std;

// Abstract base class
class Employee
{
protected:
    string name;

public:
    Employee(string n) : name(n) {}

    // Pure virtual function: makes this class abstract
    virtual double calculateSalary() = 0;

    // Virtual function to display salary
    virtual void showSalary()
    {
        cout << "Salary of " << name << " is: " << calculateSalary() << endl;
    }

    // Virtual destructor (good practice for polymorphism)
    virtual ~Employee() {}
};

// Derived class for permanent employees
class PermanentEmployee : public Employee
{
private:
    double basicSalary;
    double bonus;

public:
    PermanentEmployee(string n, double b, double bo)
        : Employee(n), basicSalary(b), bonus(bo) {}

    // Implement calculateSalary for permanent employees
    double calculateSalary() override
    {
        return basicSalary + bonus;
    }
};

// Derived class for contract employees
class ContractEmployee : public Employee
{
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(string n, double rate, int hours)
        : Employee(n), hourlyRate(rate), hoursWorked(hours) {}

    // Implement calculateSalary for contract employees
    double calculateSalary() override
    {
        return hourlyRate * hoursWorked;
    }
};

int main()
{
    // Employee e("John"); // ERROR: cannot create object of abstract class

    // Use base class pointer to access different employee types
    Employee* emp1 = new PermanentEmployee("Alice", 5000, 1000);
    Employee* emp2 = new ContractEmployee("Bob", 70, 100);

    // Polymorphic behavior
    emp1->showSalary(); // Calls PermanentEmployee::calculateSalary()
    emp2->showSalary(); // Calls ContractEmployee::calculateSalary()

    // Clean up
    delete emp1;
    delete emp2;

    return 0;
}

