#include<iostream>
#include<iomanip>
#include "Time.h"
Time::Time(int hr,int min,int sec){ //constructor
    setTime(hr,min,sec);
}
bool Time::setTime(int h,int m,int s){ //function to set time
    bool valid = true;
    if (!setHour(h)) valid = false;
    if (!setMinute(m)) valid = false;
    if (!setSecond(s)) valid = false;
    return valid; // true if all three are valid
}
bool Time::setHour(int h){ //function sets hour and it will validate hour (0-24)
    if(h>=0&&h<24){
        hour=h;
        return true;
    }
    else {
        return false; // invalid hour
    }
}
bool Time::setMinute(int m){//this function sets minute and it will validate minute(0-60) 
    if(m>=0&&m<60){
        minute=m;
        return true;
    }
    else {
        return false; // invalid minute
    }
}
bool Time::setSecond(int s){//this function will set second and will validate second(0-60)
    if(s>=0&&s<60){
        second=s;
        return true;
    }
    else {
        return false; // invalid second
    }
}
int Time::getHour() const{  //returns hour
    return hour;
}
int Time::getMinute() const{ //returns minute
    return minute;
}
int Time::getSecond() const{ //returns second
    return second;
}

void Time::printUniversal() const{  //it will display time as universal time
    std::cout<<std::setfill('0')<<std::setw(2)<<getHour()<<":"<<std::setw(2)<<getMinute()<<":"<<std::setw(2)<<getSecond();
}

void Time::printStandard() const{ //it will display time as standard time
    std::cout<<((getHour()==0||getHour()==12)?12:getHour()%12)<<":"<<std::setfill('0')<<std::setw(2)<<getMinute()<<":"<<std::setw(2)<<getSecond()<<(hour<12?" AM":" PM");
}
