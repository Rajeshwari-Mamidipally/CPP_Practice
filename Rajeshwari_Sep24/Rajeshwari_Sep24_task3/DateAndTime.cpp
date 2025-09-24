#include<iostream>
#include<iomanip>
#include "DateAndTime.h"
DateAndTime:: DateAndTime(int m,int d,int y,int hr,int min,int sec){ //constructor validating month,day,year and setting time
    month=(m>0&&m<=12)?m:1;
    year=(y>0)?y:2000;
    int daysInMonth = getDaysInMonth(month, year);
    day = (d >= 1 && d <= daysInMonth) ? d : 1;
    setTime(hr,min,sec);
    
}
// Check for leap year
bool DateAndTime::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Return number of days in a given month
int DateAndTime::getDaysInMonth(int m, int y) const {
    static const int daysPerMonth[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeapYear(y))
        return 29; // February in leap year

    return daysPerMonth[m - 1];
}

void DateAndTime::setTime(int h,int m,int s){ //function to set time
    setHour(h); 
    setMinute(m);
    setSecond(s);
}
void DateAndTime::setHour(int h){ //function sets hour and it will validate hour (0-24)
    hour=(h>=0&&h<24)?h:0;
}
void DateAndTime::setMinute(int m){//this function sets minute and it will validate minute(0-60) 
    minute=(m>=0&&m<60)?m:0;
}
void DateAndTime::setSecond(int s){//this function will set second and will validate second(0-60)
    second=(s>=0&&s<60)?s:0;
}
int DateAndTime::getHour(){  //returns hour
    return hour;
}
int DateAndTime::getMinute(){ //returns minute
    return minute;
}
int DateAndTime::getSecond(){ //returns second
    return second;
}

void DateAndTime::printDateAndTime(){ //it will display time as standard time
    std::cout<<month<<'/'<<day<<'/'<<year<<"\t"<<((getHour()==0||getHour()==12)?12:getHour()%12)<<":"<<std::setfill('0')<<std::setw(2)<<getMinute()<<":"<<std::setw(2)<<getSecond()<<(hour<12?"AM":"PM");
}
int DateAndTime::tick(){  //this function will increment the second and it show differences in hour and minute if second and minutate validation range exceed
    second++;
    if(second==60){
        second=0;
        minute++;
        if(minute==60){
            minute=0;
            hour++;
            
            if(hour==24){
                hour=0;
                day++;
                if(day>getDaysInMonth(month,year)){ //if day is greater than the days in a particular day it will increment month and assign day as 1 
                    day=1; 
                    month++;
                
                if(month>12){//if month is greater than 12 then it will increment year and make month as 1
                    month=1; 
                    year++;
                }
                 
            }
                      
         }
                
        }
    }
    return second;
}