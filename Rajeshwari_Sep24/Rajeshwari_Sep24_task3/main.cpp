#include<iostream>
#include "DateAndTime.h"
int main(){
    std::cout<<"Enter date (as month,day,year) and time(as  hour,minute,second) : ";
    int month,day,year,hour,min,sec;
    std::cin>>month>>day>>year>>hour>>min>>sec;
    DateAndTime dt(month,day,year,hour,min,sec); //creating object t
    std::cout << "Starting date and time: \n";
    dt.printDateAndTime();
    dt.tick();
    std::cout<<"\nAfter tick function date and time \n";
    dt.printDateAndTime();
    return 0;
}
