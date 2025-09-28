#include "Polynomial.h"
#include <algorithm>

// Constructor 
Polynomial::Polynomial(const std::vector<Term>& t) : terms(t) {
    // Sort terms by exponent descending
    std::sort(terms.begin(), terms.end(), [](const Term& a, const Term& b) {
        return a.exp > b.exp;
    });
}
//set function
void Polynomial::setTerm(int coeff, int exp) {
    if (coeff == 0) return; 
    for (auto& term : terms) {
        if (term.exp == exp) {
            term.coeff += coeff;
            return;
        }
    }
    terms.push_back({coeff, exp});
    std::sort(terms.begin(), terms.end(), [](const Term& a, const Term& b) {
        return a.exp > b.exp;
    });
} 
// Addition 
Polynomial Polynomial::operator+(const Polynomial& rhs) const {
    Polynomial result = *this;
    for (auto term : rhs.terms) {
        result.setTerm(term.coeff, term.exp);
    }
    return result;
}
// Subtraction 
Polynomial Polynomial::operator-(const Polynomial& rhs) const {
    Polynomial result = *this;
    for (auto term : rhs.terms) {
        result.setTerm(-term.coeff, term.exp);
    }
    return result;
}
// Multiplication 
Polynomial Polynomial::operator*(const Polynomial& rhs) const {
    Polynomial result;
    for (auto t1 : terms) {
        for (auto t2 : rhs.terms) {
            result.setTerm(t1.coeff * t2.coeff, t1.exp + t2.exp);
        }
    }
    return result;
}
// Assignment 
Polynomial& Polynomial::operator=(const Polynomial& rhs) {
    if (this != &rhs) {
        terms = rhs.terms;
    }
    return *this;
}
// Addition assignment 
Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
    *this = *this + rhs;
    return *this;
}
// Subtraction assignment
Polynomial& Polynomial::operator-=(const Polynomial& rhs) {
    *this = *this - rhs;
    return *this;
}
// Multiplication assignment
Polynomial& Polynomial::operator*=(const Polynomial& rhs) {
    *this = *this * rhs;
    return *this;
}
// Print
void Polynomial::print() const {
    if (terms.empty()) {
        std::cout << "0";
        return;
    }
    for (size_t i = 0; i < terms.size(); ++i) {
        if (i > 0 && terms[i].coeff > 0) std::cout << " + ";
        else if (terms[i].coeff < 0) std::cout << " - ";

        int absCoeff = std::abs(terms[i].coeff);
        if (absCoeff != 1 || terms[i].exp == 0) std::cout << absCoeff;

        if (terms[i].exp > 0) {
            std::cout << "x";
            if (terms[i].exp > 1) std::cout << "^" << terms[i].exp;
        }
    }
    std::cout << std::endl;
}