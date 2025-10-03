#include <iostream>
#include "Rajeshwari_Sep26_task4_RationalNumber.h"

int main() {
    RationalNumber r1(4, 8);   
    RationalNumber r2(-3, 9);  
    RationalNumber r3(2, -5);  

    std::cout << "r1: " << r1 << "\n";
    std::cout << "r2: " << r2 << "\n";
    std::cout << "r3: " << r3 << "\n";

    std::cout << "r1 + r2 = " << r1 + r2 << "\n";
    std::cout << "r1 - r3 = " << r1 - r3 << "\n";
    std::cout << "r2 * r3 = " << r2 * r3 << "\n";
    std::cout << "r1 / r3 = " << r1 / r3 << "\n";

    std::cout << std::boolalpha;
    std::cout << "r1 == r2? " << (r1 == r2) << "\n";
    std::cout << "r1 > r3? " << (r1 > r3) << "\n";

    return 0;
}

