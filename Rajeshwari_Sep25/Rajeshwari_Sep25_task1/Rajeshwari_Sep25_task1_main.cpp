#include<iostream>
#include "Rajeshwari_Sep25_task1_SavingsAccount.h"
int main(){
    double balance1,balance2; 
    std::cout<<"Enter the balance1 and balance2 : ";
    std::cin>>balance1>>balance2;//taking input from user
    SavingsAccount saver1(balance1);//creating object 1
    SavingsAccount saver2(balance2);//creating object 2
    double interest;
    std::cout<<"Enter interest : ";
    std::cin>>interest; //taking input from user
    interest/=100;
    SavingsAccount::modifyInterestRate(interest); //setting interest
    saver1.calculateMonthlyInterest(); //calculating monthly interest and adding it to savings of object 1
    saver2.calculateMonthlyInterest();//calculating monthly interest and adding it to savings of object 2
    std::cout<<"saving balance : "<<"\n"; //displaying savings of object 1 and object 2
    std::cout<<"saver 1 : "<<saver1.display()<<'\n';
    std::cout<<"saver 2 : "<<saver2.display()<<'\n';
    std::cout<<"Enter new interest : "; //taking new interest from user
    double newInterest;
    std::cin>>newInterest;
    newInterest/=100;
    SavingsAccount::modifyInterestRate(newInterest); //setting interest to new interest
    saver1.calculateMonthlyInterest(); //calculating monthly interest and adding it to savings of object 1
    saver2.calculateMonthlyInterest(); //calculating monthly interest and adding it to savings of object 2 
    std::cout<<"Ater modifying interest saving balance : "<<std::endl; //displaying object 1 and object2 balance
    std::cout<<"saver 1 : "<<saver1.display()<<'\n';
    std::cout<<"saver 2 : "<<saver2.display()<<'\n';  
    return 0;


}
