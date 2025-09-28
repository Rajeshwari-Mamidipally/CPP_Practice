#ifndef COMPLEX_H
#define COMPLEX_H
class Complex{
    public:
    Complex( double = 0.0, double = 0.0 );
    Complex operator+( const Complex & ) const;
    Complex operator-( const Complex & ) const;
    Complex operator*( const Complex &) const;
    bool operator==(const Complex &) const;
    bool operator!=(const Complex &) const;
    friend std::ostream& operator<<(std::ostream &out, const Complex &c);
    friend std::istream& operator>>(std::istream &in, Complex &c);
   
    private:
    double real;
    double imaginary;
};

#endif
