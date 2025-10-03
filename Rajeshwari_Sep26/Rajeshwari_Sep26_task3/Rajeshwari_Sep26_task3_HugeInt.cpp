#include<iostream>
#include<cctype>
#include "Rajeshwari_Sep26_task3_HugeInt.h"
HugeInt::HugeInt(long value){  //constructor
    for(int i=0;i<digits;i++)
    integer[i]=0;
    for(int j=digits-1;value!=0&&j>=0;j--){
        integer[j]=value%10;
        value/=10;
    }
}
HugeInt::HugeInt(const std::string &number){
    for(int i=0;i<digits;i++)
    integer[i]=0;
    int length=number.size();
    for(int j=digits-length,k=0;j<digits;j++,k++)
    if(isdigit(number[k]))
    integer[j]=number[k]-'0';
}
//Addition functions
HugeInt HugeInt::operator+(const HugeInt &op2) const{
    HugeInt temp;
    int carry=0;
    for(int i=digits-1;i>=0;i--){
        temp.integer[i]=integer[i]+op2.integer[i]+carry;
         carry = temp.integer[i] / 10;
        temp.integer[i] %= 10;
    }
    return temp;
}
HugeInt HugeInt::operator+(int op2) const{
    return *this+HugeInt(op2);
}
HugeInt HugeInt::operator+(const std::string &op2) const{
    return *this + HugeInt(op2);
}
//multiplication functions
HugeInt HugeInt::operator*(const HugeInt &op2) const{
HugeInt temp;
    int buffer[HugeInt::digits] = {0};
    for (int i = digits - 1; i >= 0; --i) {
        if (integer[i] == 0) continue;
        for (int j = digits - 1; j >= 0; --j) {
            if (op2.integer[j] == 0) continue;
            int p = i + j - (HugeInt::digits - 1); 
            if (p < 0) continue; 
            buffer[p] += integer[i] * op2.integer[j];
        }
    }
    for (int k = HugeInt::digits - 1; k > 0; --k) {
        int carry = buffer[k] / 10;
        buffer[k] %= 10;
        buffer[k - 1] += carry;
    }
    for (int k = 0; k < HugeInt::digits; ++k) temp.integer[k] = static_cast<short>(buffer[k]);

    return temp;
}
HugeInt HugeInt::operator*(int op2) const{
    return *this*HugeInt(op2);
}
HugeInt HugeInt::operator*(const std::string &op2)const{
    return *this*HugeInt(op2);
}
//division functions
HugeInt HugeInt::operator/(const HugeInt &op2) const{
    bool divisorIsZero = true;
    for (int i = 0; i < digits; ++i) if (op2.integer[i] != 0) { divisorIsZero = false; break; }
    if (divisorIsZero) {
        std::cerr << "Error: Division by zero in HugeInt::operator/.\n";
        std::exit(1);
    }

    HugeInt quotient; 
    int rem[HugeInt::digits] = {0}; 

    auto multSmall = [&](int prod[], const short div[], int small) {
        int carry = 0;
        for (int p = HugeInt::digits - 1; p >= 0; --p) {
            int v = div[p] * small + carry;
            prod[p] = v % 10;
            carry = v / 10;
        }
        
    };

    for (int pos = 0; pos < HugeInt::digits; ++pos) {

        for (int k = 0; k < HugeInt::digits - 1; ++k) rem[k] = rem[k + 1];
        rem[HugeInt::digits - 1] = this->integer[pos];

        int qdigit = 0;
        for (int trial = 9; trial >= 1; --trial) {
            int prod[HugeInt::digits] = {0};
            multSmall(prod, op2.integer, trial);
           
            int cmp = 0;
            for (int t = 0; t < HugeInt::digits; ++t) {
                if (prod[t] < rem[t]) { cmp = -1; break; }
                if (prod[t] > rem[t]) { cmp = 1; break; }
            }

            if (cmp <= 0) {
                int borrow = 0;
                for (int s = HugeInt::digits - 1; s >= 0; --s) {
                    int val = rem[s] - prod[s] - borrow;
                    if (val < 0) { val += 10; borrow = 1; }
                    else borrow = 0;
                    rem[s] = val;
                }
                qdigit = trial;
                break;
            }
        }
        quotient.integer[pos] = static_cast<short>(qdigit);
    }

    return quotient;

}
HugeInt HugeInt::operator/(int op2) const{
    return *this/HugeInt(op2);
}
HugeInt HugeInt::operator/(const std::string &op2)const{
    return*this/HugeInt(op2);
}
// equality functions
bool HugeInt::operator==(const HugeInt &op2) const {
    for (int i = 0; i < digits; i++) {
        if (integer[i] != op2.integer[i])
            return false;
    }
    return true;
}
bool HugeInt::operator==(int op2 ) const{
    return *this==HugeInt(op2);
    
}
bool HugeInt::operator==(const std::string &op2)const{
    return *this==HugeInt(op2);
}
//not equals to functions
bool HugeInt::operator!=(const HugeInt &op2) const {
    return !(*this == op2);
}

bool HugeInt::operator!=(int op2) const {
    return !(*this == HugeInt(op2));
}

bool HugeInt::operator!=(const std::string &op2) const {
    return !(*this == HugeInt(op2));
}
//less than function
bool HugeInt::operator<(const HugeInt &op2) const {
    for (int i = 0; i < digits; i++) {
        if (integer[i] < op2.integer[i])
            return true;
        else if (integer[i] > op2.integer[i])
            return false;
    }
    return false; 
}
//less than or equals to function
bool HugeInt::operator<=(const HugeInt &op2) const {
    return (*this < op2) || (*this == op2);
}
//greater than function
bool HugeInt::operator>(const HugeInt &op2) const {
    return !(*this <= op2);
}
//greater than or equals to function
bool HugeInt::operator>=(const HugeInt &op2) const {
    return !(*this < op2);
}
//stream output
std::ostream& operator<<(std::ostream &output,const HugeInt &num){
    int i;
    for(i=0;(num.integer[i]==0)&&(i<=HugeInt::digits);i++);
    if(i==HugeInt::digits)
    output<<0;
    else
    for(;i<HugeInt::digits;i++)
    output<<num.integer[i];
    return output;
}

