#ifndef RAJESHWARI_SEP25_TASK1_SAVINGSACCOUNT_H
#define RAJESHWARI_SEP25_TASK1_SAVINGSACCOUNT_H
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
