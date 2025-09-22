#include<iostream>
#include "Account.h"
int main(){
    Account account1(45000);
    Account account2(50000);
    account1.credit(15000);
    account1.debit(10000);
    std::cout<<"Account1 Balance : "<<account1.getBalance()<<'\n';
    account2.credit(5000);
    account2.debit(5000);
    std::cout<<"Account2 Balance : "<<account2.getBalance()<<'\n';
    return 0;
}