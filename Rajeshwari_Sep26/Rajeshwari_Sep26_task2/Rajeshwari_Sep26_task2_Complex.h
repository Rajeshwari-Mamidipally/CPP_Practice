#ifndef RAJESHWARI_SEP26_TASK2_COMPLEX_H
#define RAJESHWARI_SEP26_TASK2_COMPLEX_H
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

