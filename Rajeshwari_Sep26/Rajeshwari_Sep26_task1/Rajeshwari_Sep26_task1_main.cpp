#include<iostream>
#include "DoubleSubscriptedArray.h"

int main() {
    DoubleSubscriptedArray integers1(3, 5); //creating object 1
    DoubleSubscriptedArray integers2(2,3);//creating object 2

    std::cout << "Enter the elements into two arrays:\n";
    std::cin >> integers1 >> integers2;

    std::cout << "\nAfter input, the Arrays contain:\n"
              << "integers1:\n" << integers1
              << "integers2:\n" << integers2;

    std::cout << "\nEvaluating: integers1 != integers2" << std::endl;
    if(integers1 != integers2)
        std::cout << "integers1 and integers2 are not equal" << std::endl;

    DoubleSubscriptedArray integers3(integers1);
    std::cout << "\nSize of Array integers3 is " << integers3.getSize()
              << "\nArray after initialization:\n" << integers3;

    std::cout << "\nAssigning integers2 to integers1:\n";
    integers1 = integers2;

    std::cout << "integers1:\n" << integers1
              << "integers2:\n" << integers2;

    std::cout << "\nEvaluating: integers1 == integers2" << std::endl;
    if(integers1 == integers2) {
        std::cout <<"Both integers1 and integers2 are equal" << std::endl;
    }

    std::cout << "\nAssigning 1000 to integers1[5]" << std::endl;
    integers1[5] = 1000;
    std::cout << "integers1:\n" << integers1;

    std::cout << "\nAssigning 50 to integers1(1,2)" << std::endl;
    integers1(1,2) = 50;
    std::cout << "integers1:\n" << integers1;

    return 0;
}
