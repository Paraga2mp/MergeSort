#include "Employee.h"

const int RECORD = 40;


Employee::Employee() : employee_id(""), lastName(""), firstName(""), address(""),
                        city(""), province(""), postalCode(""), phone(""), gender('0'),
                        age(-1), dependents(-1), dept(""), uni('0'), hourlyRate(0.0) {}

Employee::~Employee() {}

// assign values to the Employee objects
Employee Employee::operator<<(string data) {

    stringstream ss;
    ss << data;

    getline(ss, employee_id, '\t');
    getline(ss, lastName, '\t');
    getline(ss, firstName, '\t');
    getline(ss, address, '\t');
    getline(ss, city, '\t');
    getline(ss, province, '\t');
    getline(ss, postalCode, '\t');
    getline(ss, phone, '\t');
    ss >> gender;
    ss >> age;
    ss >> dependents;
    ss >> dept;
    ss >> uni;
    ss >> hourlyRate;

    return *this;
}

// override << operator
ostream& operator<<(ostream& output, Employee& emp) {

    output << emp.employee_id << "\t" << emp.lastName << "\t" << emp.firstName << "\t" << emp.address << "t" << emp.city <<
           "\t" << emp.province << "\t" << emp.postalCode << "\t" << emp.phone << "\t" << emp.gender << "\t" << emp.age << "\t" <<
           emp.dependents << "\t" << emp.dept << "\t" << emp.uni << "\t" << emp.hourlyRate << endl;

    return output;

}

// write array elements to a file
void Employee::SaveToFile(Employee* emp) {

    ofstream outputFile;
    string outPath = "..\\output\\Output.txt";
    outputFile.open(outPath);

    for (int i = 0; i < RECORD; i++) {
        outputFile << emp[i];
    }

    outputFile << "\n";

}
