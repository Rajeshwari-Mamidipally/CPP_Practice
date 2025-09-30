#include <iostream>
int main() {
    double number1 = 7.3f, number2;    // Declare floating-point variables as double
    char *ptr;                        // pointer to char
    char s1[100] = "";           // initialized string
    char s2[100] = "";           // initialized string

    //Declare pointer to  an object of type double. 
    double *fPtr;

    //Assign the address of number1 to pointer variable fPtr
    fPtr = &number1;

    //Print the value of the object pointed to by fPtr
    std::cout << "Value pointed to by fPtr: " << *fPtr << '\n';

    //Assign the value of the object pointed to by fPtr to variable number2
    number2 = *fPtr;

    //Print the value of number2
    std::cout << "Value of number2: " << number2 << '\n';

    //Print the address of number1
    std::cout << "Address of number1: " << &number1 << '\n';

    //Print the address stored in fPtr
    std::cout << "Address stored in fPtr: " << fPtr << '\n';
    std::cout<<(fPtr==&number1)?1:0;
    std::cout<<" (if it is '1' it means fPtr and &number1 values are same , if it is '0' fPtr and &number1 values are different) ";
    

    return 0;
}
