#include <iostream>
#include "GradeBook.h"
using namespace std;

int main() {
    GradeBook myGradeBook("CS101 Introduction to Programming","Prof. In-Young Ko");

    myGradeBook.displayMessage(); //calling method to display the message 

    return 0;
}