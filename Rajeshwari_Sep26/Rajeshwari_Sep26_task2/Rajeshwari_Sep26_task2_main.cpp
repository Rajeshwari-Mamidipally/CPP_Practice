#include<iostream>
#include "Complex.h"
int main(){
    Complex y;
    Complex z;
    std::cin>>y;
    std::cin>>z;
    std::cout << "\nYou entered:\n";
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;

    std::cout << "\nResults:\n";
    std::cout << "Sum = " << y+z << std::endl;
    std::cout << "Difference = " << y-z << std::endl;
    std::cout << "Product = " << y*z << std::endl;

    if (y == z)
        std::cout << "y and z are equal" << std::endl;
    else
        std::cout << "y and z are NOT equal" << std::endl;
    
   return 0;

}