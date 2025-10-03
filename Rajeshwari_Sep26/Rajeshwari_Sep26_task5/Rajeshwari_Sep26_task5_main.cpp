#include "Rajeshwari_Sep26_task5_Polynomial.h"

int main() {
    Polynomial p1;
    p1.setTerm(2, 4); // 2x^4
    p1.setTerm(3, 2); // 3x^2
    p1.setTerm(1, 0); // 1

    Polynomial p2;
    p2.setTerm(1, 3); // x^3
    p2.setTerm(2, 2); // 2x^2
    p2.setTerm(4, 0); // 4

    std::cout << "P1: "; p1.print();
    std::cout << "P2: "; p2.print();

    Polynomial sum = p1 + p2;
    std::cout << "Sum: "; sum.print();

    Polynomial diff = p1 - p2;
    std::cout << "Difference: "; diff.print();

    Polynomial prod = p1 * p2;
    std::cout << "Product: "; prod.print();

    return 0;
}

