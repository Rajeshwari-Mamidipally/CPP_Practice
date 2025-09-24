#include<iostream>
#include "Date.h"
Date::Date(int m,int d,int y){ //constructor validating month,day,year
    month=(m>0&&m<=12)?m:1;
    year=(y>0)?y:2000;
    int daysInMonth = getDaysInMonth(month, year);
    day = (d >= 1 && d <= daysInMonth) ? d : 1;
    
}
// Check for leap year
bool Date::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Return number of days in a given month
int Date::getDaysInMonth(int m, int y) const {
    static const int daysPerMonth[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeapYear(y))
        return 29; // February in leap year

    return daysPerMonth[m - 1];
}
void Date::print(){  //this function will display date
    std::cout<<month<<'/'<<day<<'/'<<year;
}
void Date::nextDay(){ //this function will increment day
    day++;
    if(day>getDaysInMonth(month,year)) //if day is greater than the days in a particular day it will increment month and assign day as 1 
    {
        month++;
        day=1;
    }
    if(month>12){//if month is greater than 12 then it will increment year and make month as 1
        year++;
        month=1;
    }
}