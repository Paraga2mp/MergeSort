
#ifndef ASSIGNMENT4_MERGESORT_H
#define ASSIGNMENT4_MERGESORT_H

#include "Employee.h"

class MergeSort {

public:

    bool IsLessThanEqualTo (Employee &emp1, Employee &emp2, int index);

    bool IsGreaterThan (Employee &emp1, Employee &emp2, int index);

    void Split(Employee *inarray, int len, Employee *outarray1, int *outsize1,
               Employee *outarray2, int *outsize2, int index);

    int Merge(Employee *outarray, int *outsize, Employee *inarray1, int insize1,
              Employee *inarray2, int insize2, int index);

    void Mergesort(Employee* array, int len, int index);

};


#endif //ASSIGNMENT4_MERGESORT_H
