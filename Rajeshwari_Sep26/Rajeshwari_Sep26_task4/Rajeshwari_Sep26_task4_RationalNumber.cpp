#include "Rajeshwari_Sep26_task4_RationalNumber.h"
#include <numeric>  
#include <stdexcept> 

//Constructor
RationalNumber::RationalNumber(int num, int denom) {
    if (denom == 0)
        throw std::invalid_argument("Denominator cannot be zero");
    numerator = num;
    denominator = denom;
    simplify();
}

int RationalNumber::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void RationalNumber::simplify() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    if (denominator < 0) {  //if denominator is negative then add -to numerator and denominator
        numerator = -numerator;
        denominator = -denominator;
    }
}

//addition of rational numbers
RationalNumber RationalNumber::operator+(const RationalNumber &rhs) const {
    return RationalNumber(numerator * rhs.denominator + rhs.numerator * denominator, denominator * rhs.denominator);
}
//substraction of rational numbers
RationalNumber RationalNumber::operator-(const RationalNumber &rhs) const {
    return RationalNumber(numerator * rhs.denominator - rhs.numerator * denominator,denominator * rhs.denominator);
}
//multiplication of rational numbers
RationalNumber RationalNumber::operator*(const RationalNumber &rhs) const {
    return RationalNumber(numerator * rhs.numerator, denominator * rhs.denominator);
}
//division of rational numbers 
RationalNumber RationalNumber::operator/(const RationalNumber &rhs) const {
    if (rhs.numerator == 0)
        throw std::invalid_argument("Division by zero");
    return RationalNumber(numerator * rhs.denominator, denominator * rhs.numerator);
}

//comparison function
bool RationalNumber::operator==(const RationalNumber &rhs) const {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}
//not equals to comparison function
bool RationalNumber::operator!=(const RationalNumber &rhs) const {
    return !(*this == rhs);
}
//less than function
bool RationalNumber::operator<(const RationalNumber &rhs) const {
    return numerator * rhs.denominator < rhs.numerator * denominator;
}
//less than or equals to function
bool RationalNumber::operator<=(const RationalNumber &rhs) const {
    return *this < rhs || *this == rhs;
}
//greater than function 
bool RationalNumber::operator>(const RationalNumber &rhs) const {
    return !(*this <= rhs);
}
//greater than or equals to function
bool RationalNumber::operator>=(const RationalNumber &rhs) const {
    return !(*this < rhs);
}

//stream output
std::ostream& operator<<(std::ostream &out, const RationalNumber &r) {
    out << r.numerator;
    if (r.denominator != 1) out << "/" << r.denominator;
    return out;
}

