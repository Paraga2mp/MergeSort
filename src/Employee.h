#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#ifndef ASSIGNMENT4_EMPLOYEE_H
#define ASSIGNMENT4_EMPLOYEE_H

class Employee {

public:

    string employee_id;
    string lastName;
    string firstName;
    string address;
    string city;
    string province;
    string postalCode;
    string phone;
    char gender;
    int age;
    int dependents;
    string dept;
    char uni;
    double hourlyRate;

    Employee();
    virtual ~Employee();

    Employee operator<<(string data);
    friend ostream& operator<<(ostream& output, Employee& emp);
    void SaveToFile(Employee* emp);

};

#endif //ASSIGNMENT4_EMPLOYEE_H
