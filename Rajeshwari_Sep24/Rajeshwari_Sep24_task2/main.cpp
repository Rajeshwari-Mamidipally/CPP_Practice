#include<iostream>
#include "Date.h"
int main(){
    std::cout<<"Enter date as month,day,year : ";
    int month,day,year;
    std::cin>>month>>day>>year;
    Date date1(month,day,year); //creating object
    std::cout<<"Date1 = ";
    date1.print();
    date1.nextDay();
    std::cout<<"\n";
    date1.print();
    return 0;

}
