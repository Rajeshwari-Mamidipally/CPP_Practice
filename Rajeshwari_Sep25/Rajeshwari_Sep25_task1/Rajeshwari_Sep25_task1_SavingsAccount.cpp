#include<iostream>
#include "SavingsAccount.h"
double SavingsAccount::annualInterestRate = 0.0; // Initial static value of annual interest rate
SavingsAccount::SavingsAccount(double balance){//constructor
    savingsBalance=balance;
    monthlyInterest=0;
}

void SavingsAccount::calculateMonthlyInterest(){//calculating monthly interest and adding it to balance
    monthlyInterest=savingsBalance*annualInterestRate/12; //calculating monthly interest by multiplying balance with annual interest rate and dividing by 12
    savingsBalance+=monthlyInterest; //adding monthly interest to saving balance
    
}
void  SavingsAccount::modifyInterestRate(double newInterest){ //setting interest 
    annualInterestRate=newInterest;

}
double SavingsAccount::display(){ //it returns the balance;
    return savingsBalance;
}