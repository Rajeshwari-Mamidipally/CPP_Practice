#ifndef RAJESHWARI_SEP26_TASK5_POLYNOMIAL_H
#define RAJESHWARI_SEP26_TASK5_POLYNOMIAL_H

#include <iostream>
#include <vector>

struct Term {
    int coeff;  
    int exp;    
};

class Polynomial {
private:
    std::vector<Term> terms; // dynamic array of terms

public:
    // Constructors
    Polynomial() = default;
    Polynomial(const std::vector<Term>& t);

    // Destructor
    ~Polynomial() = default;

    // Set and get functions
    void setTerm(int coeff, int exp); 
    std::vector<Term> getTerms() const { return terms; }

    // Operator overloads
    Polynomial operator+(const Polynomial& rhs) const;
    Polynomial operator-(const Polynomial& rhs) const;
    Polynomial operator*(const Polynomial& rhs) const;
    Polynomial& operator=(const Polynomial& rhs);

    Polynomial& operator+=(const Polynomial& rhs);
    Polynomial& operator-=(const Polynomial& rhs);
    Polynomial& operator*=(const Polynomial& rhs);

    // Print function
    void print() const;
};

#endif

