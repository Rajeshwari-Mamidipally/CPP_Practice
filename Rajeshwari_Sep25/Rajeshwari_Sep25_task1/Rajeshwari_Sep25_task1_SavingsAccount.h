#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
class SavingsAccount{
    private:
    static double annualInterestRate;
    double savingsBalance;
    double monthlyInterest;
    public:
    SavingsAccount(double );//constructor
    void calculateMonthlyInterest(); //calculating monthly interest
    static void modifyInterestRate(double newInterest);//modifying interest
    double display();//displays balance

};
#endif