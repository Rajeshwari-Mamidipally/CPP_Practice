#include <iostream>
#include "Account.h"
Account::Account(int balance){ //constructor validating balance assign balance =0 if balance is less than zero else set balance
 
    if(balance<0){
        setBalance(0);
        std::cout<<"Initial Balance was invalid.\n";
    }
    else{
        setBalance(balance);
    }
}
void Account::setBalance(int amount){ //set balance 
    balance=amount;
}
int Account::getBalance(){ //returns balance
    return balance;
}
void Account::credit(int addbalance){ //credit the balance
    balance=getBalance()+addbalance;
}
void Account::debit(int debitamount){//debit balance if balance is >=debit amount else print error message
    if(debitamount>getBalance()){
        std::cout<<"Debit amount exceeded account balance.\n";
    }
    else{
        balance-=debitamount;
    }
}
