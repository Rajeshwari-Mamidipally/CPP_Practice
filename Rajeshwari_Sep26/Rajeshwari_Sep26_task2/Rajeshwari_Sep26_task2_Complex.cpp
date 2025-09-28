#include<iostream>
#include "Complex.h"
Complex::Complex(double realPart,double imaginaryPart)//constructor
:
real(realPart),
imaginary(imaginaryPart){

}
//addition 
Complex Complex::operator+(const Complex &operand2) const{
      return Complex( real + operand2.real,imaginary + operand2.imaginary);
}
//substraction
Complex Complex::operator-(const Complex &operand2) const{
   return Complex(real - operand2.real,imaginary - operand2.imaginary);
    
}
//multiplication
Complex Complex::operator*(const Complex &operand2) const{
    double newReal = (real * operand2.real) - (imaginary * operand2.imaginary);
    double newImaginary = (real * operand2.imaginary) + (imaginary * operand2.real);
    return Complex(newReal, newImaginary);
    
}
//comparison(equals to) function
bool Complex::operator==(const Complex &operand2) const{
    return(real==operand2.real&&imaginary==operand2.imaginary);
}
//comparison(not equals to) function       
bool Complex::operator!=(const Complex &operand2) const{
    return(real!=operand2.real||imaginary!=operand2.imaginary);
}   
//stream output
std::ostream& operator<<(std::ostream &out, const Complex &c) {
    out << "(" << c.real << "," << c.imaginary << ")";
    return out;
}
//stream input
std::istream& operator>>(std::istream &in, Complex &c) {
    std::cout << "Enter real part: ";
    in >> c.real;
    std::cout << "Enter imaginary part: ";
    in >> c.imaginary;
    return in;
}
