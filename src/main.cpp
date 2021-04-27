#include <iostream>
#include <sstream>
#include "MergeSort.h"

using namespace std;

const int RECORD = 40;

// get the field number from command line and convert to an integer
int GetFieldNo(string fieldNo) {

    string initialStr = "-field=";
    string num = "";
    int number;

    for(int i = 0; i < fieldNo.length(); i++) {

        if(i < initialStr.length()) {
            // check if initialStr id equal to fieldNo
            if(initialStr[i] != fieldNo[i]) {

                cout << "Wrong field no" << endl;
            }
        }
        else {
            // check if fieldNo is digit
            if(!isalpha(fieldNo[i])) {

                num += fieldNo[i];
            }
            else {

                cout << "Wrong field no" << endl;
            }
        }
    }
    // convert string num to integer value
    if((num != "") && stoi(num) >= 0 && stoi(num) <= 13) {

        number = stoi(num);
    }
    else {

        cout << "Wrong field number" << endl;
    }

    return number;
}



int main(int argc, char** argv) {

    string fileName;
    string line;

    //gets the file name from the main function argument
    if(argc > 1) {

        fileName = argv[1];
    }

    // get and convert the field number from command line
    string field = argv[2];
    int fieldNo = GetFieldNo(field);

    Employee emp;
    Employee obj[RECORD];
    MergeSort mst;
    int i = 0;

    //stream to read from the file
    fstream readFile(fileName);

    if(readFile.is_open()) {
        // read the 1st line (heading) from the file
        getline(readFile, line);

        while (getline(readFile, line)) {
            // read and store the file content into an array
            emp << line;
            obj[i++] << line;
        }
    }
    else {

        cout << "Unable to open the file" << endl;
    }

    // call the Mergesort function
    mst.Mergesort(obj, RECORD, fieldNo);

    // call the function to write into a file
    emp.SaveToFile(obj);


    return 0;
}