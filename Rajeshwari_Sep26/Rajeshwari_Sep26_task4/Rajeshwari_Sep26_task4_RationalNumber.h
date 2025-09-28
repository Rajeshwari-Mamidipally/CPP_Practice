#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

class RationalNumber {
private:
    int numerator;
    int denominator;

    void simplify();  
    static  int gcd(int,int);

public:
    // Constructor
    RationalNumber(int num = 0, int denom = 1);
   

    // Arithmetic operators
    RationalNumber operator+(const RationalNumber &rhs) const;
    RationalNumber operator-(const RationalNumber &rhs) const;
    RationalNumber operator*(const RationalNumber &rhs) const;
    RationalNumber operator/(const RationalNumber &rhs) const;

    // Relational and equality operators
    bool operator==(const RationalNumber &rhs) const;
    bool operator!=(const RationalNumber &rhs) const;
    bool operator<(const RationalNumber &rhs) const;
    bool operator<=(const RationalNumber &rhs) const;
    bool operator>(const RationalNumber &rhs) const;
    bool operator>=(const RationalNumber &rhs) const;

    // Stream output
    friend std::ostream& operator<<(std::ostream &out, const RationalNumber &r);
};

#endif
