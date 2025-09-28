#include <iostream>
#include "HugeInt.h"

int main() {
    HugeInt num1(12345);                        
    HugeInt num2("98765432109876543210");       
    HugeInt num3("0");                          

    std::cout << "Initial numbers:\n";
    std::cout << "num1 = " << num1 << "\n";
    std::cout << "num2 = " << num2 << "\n";
    std::cout << "num3 = " << num3 << "\n\n";

    // Addition
    HugeInt sum = num1 + num2;
    std::cout << "Addition test:\n";
    std::cout << num1 << " + " << num2 << " = " << sum << "\n\n";

    // Addition with int and string
    HugeInt sum2 = num1 + 99999;
    HugeInt sum3 = num1 + std::string("1234567890");
    std::cout << "Mixed addition:\n";
    std::cout << num1 << " + 99999 = " << sum2 << "\n";
    std::cout << num1 << " + \"1234567890\" = " << sum3 << "\n\n";

    // Multiplication
    HugeInt prod = num1 * num2;
    std::cout << "Multiplication test:\n";
    std::cout << num1 << " * " << num2 << " = " << prod << "\n\n";

    HugeInt prod2 = num1 * 25;
    HugeInt prod3 = num1 * std::string("123");
    std::cout << "Mixed multiplication:\n";
    std::cout << num1 << " * 25 = " << prod2 << "\n";
    std::cout << num1 << " * \"123\" = " << prod3 << "\n\n";

    // Division
    HugeInt big("100000000000000000000000000000");
    HugeInt small("12345");
    HugeInt quotient = big / small;
    std::cout << "Division test:\n";
    std::cout << big << " / " << small << " = " << quotient << "\n\n";

    HugeInt quotient2 = big / 10;
    HugeInt quotient3 = big / std::string("999");
    std::cout << "Mixed division:\n";
    std::cout << big << " / 10 = " << quotient2 << "\n";
    std::cout << big << " / \"999\" = " << quotient3 << "\n\n";

    // Relational and equality tests
    HugeInt a("123456789");
    HugeInt b("123456789");
    HugeInt c("987654321");

    std::cout << "Relational and equality tests:\n";
    std::cout << a << " == " << b << " ? " << (a == b ? "true" : "false") << "\n";
    std::cout << a << " != " << c << " ? " << (a != c ? "true" : "false") << "\n";
    std::cout << a << " < " << c << " ? " << (a < c ? "true" : "false") << "\n";
    std::cout << c << " > " << a << " ? " << (c > a ? "true" : "false") << "\n";
    std::cout << a << " <= " << b << " ? " << (a <= b ? "true" : "false") << "\n";
    std::cout << c << " >= " << a << " ? " << (c >= a ? "true" : "false") << "\n\n";

    return 0;
}
