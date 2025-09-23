#include<iostream>
#include "DuplicateElimination.h"
using namespace std;
DuplicateElimination::DuplicateElimination()
:
count(0){}
//function to check if a number is a duplicate
bool DuplicateElimination::isDuplicate(int num) const {
    for (int i = 0; i < count; i++) {
        if (array[i] == num) {   //if element is already present it will return true
            return true;
        }
    }
    return false;    //if element is not in array then it returns false
}
// Function to read 20 numbers
void DuplicateElimination::readNumbers() {
    cout << "Enter 20 numbers between " << 10 << " and " << 100 << " inclusive:\n";

    for (int i = 0; i < sizeOfArray; i++) {
        int num;
        cout << "Number " << (i + 1) << ": ";
        cin >> num;

        // Validating range
        if (num < 10 || num > 100) {
            cout << "Invalid input! Number must be between " <<10 << " and " << 100 << ". Try again.\n";
            i--; 
            continue;
        }

        // Check and store if not duplicate
        if (!isDuplicate(num)) {
            array[count] = num; //store if array does not contain this element
            count++;
        } else {
            cout << "Duplicate detected! Number not added.\n"; 
        }
    }
}
// Function to display all unique numbers
void DuplicateElimination::displayUnique() const {
    cout << "\nThe unique numbers entered are:\n";
    for (int i = 0; i < count; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}