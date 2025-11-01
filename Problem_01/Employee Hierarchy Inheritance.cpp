#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee {
protected:
    string name;
    double salary;

public:
    void showInfo() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

// Manager class inherits from Employee
// Using protected inheritance hides Employee's public members from main()
class Manager : protected Employee {
public:
    // Manager can modify salary (protected member inherited)
    void setSalary(double s) {
        salary = s;  // OK: salary is protected in Employee
    }

    void setName(string n) {
        name = n;  // OK: name is protected in Employee
    }

    void display() {
        showInfo(); // OK: showInfo() is now protected in Manager
    }
};

// Sub_Manager class inherits from Manager
class Sub_Manager : public Manager {
public:
    void increaseSalary(double increment) {
        salary += increment; // OK: salary is inherited as protected
    }

    void show() {
        display(); // Can call Manager's method to indirectly show info
    }
};

int main() {
    Manager m;
    // m.showInfo(); // ERROR: showInfo() is not accessible here
    m.setName("John");
    m.setSalary(5000);
    // m.display(); // ERROR: display() is public in Manager, can be public if we want
    // To show info, we need to use Sub_Manager or internal Manager method
    Sub_Manager sm;
    sm.setName("Alice");
    sm.setSalary(6000);
    sm.increaseSalary(500);
    sm.show(); // Works: indirect access to showInfo() through protected inheritance
    return 0;
}

