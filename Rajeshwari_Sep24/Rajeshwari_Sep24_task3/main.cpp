#include<iostream>
#include "DateAndTime.h"
int main(){
    DateAndTime dt(4,30,2004,23,59,59); //creating object t
    std::cout << "Starting date and time: \n";
    dt.printDateAndTime();
    dt.tick();
    std::cout<<"\nAfter tick function date and time \n";
    dt.printDateAndTime();
    return 0;

   
}