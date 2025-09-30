#include <iostream>
//Prototype for exchange
void exchange(double *x, double *y);

//Prototype for evaluate
int evaluate(int x, int (*poly)(int));

// Example function to use with evaluate
int cube(int n) {
    return n * n * n;
}

int main() {
    //Initialize character array vowel
    char vowel[6] = "AEIOU";
    std::cout << "Vowels: " << vowel <<std::endl;
    std::cout<<"Enter a and b values : "<<'\n';
    double a, b;
    std::cin>>a>>b;
    std::cout << "Before exchange: a = " << a << ", b = " << b <<std::endl;
    exchange(&a, &b);
    std::cout << "After exchange: a = " << a << ", b = " << b <<std::endl;
    int x;
    std::cout<<"Enter  x value : \n";
    std::cin>>x;
    int result = evaluate(x, cube);
    std::cout << "Evaluate result: " << result <<std::endl;

    return 0;
}

//Function header and definition
void exchange(double *x, double *y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}

//Function header and definition
int evaluate(int x, int (*poly)(int)) {
    return poly(x); // Call the function passed as pointer
}
