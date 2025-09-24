#include<iostream>
#include "Date.h"
int main(){
    Date date1(7,4,2004); //creating object
    std::cout<<"Date1 = ";
    date1.print();
    date1.nextDay();
    std::cout<<"\n";
    date1.print();
    return 0;
}