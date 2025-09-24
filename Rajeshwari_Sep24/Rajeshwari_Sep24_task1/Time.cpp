#include<iostream>
#include<iomanip>
#include "Time.h"
Time::Time(int hr,int min,int sec){ //constructor
    setTime(hr,min,sec);
}
void Time::setTime(int h,int m,int s){ //function to set time
    setHour(h); 
    setMinute(m);
    setSecond(s);
}
void Time::setHour(int h){ //function sets hour and it will validate hour (0-24)
    hour=(h>=0&&h<24)?h:0;
}
void Time::setMinute(int m){//this function sets minute and it will validate minute(0-60) 
    minute=(m>=0&&m<60)?m:0;
}
void Time::setSecond(int s){//this function will set second and will validate second(0-60)
    second=(s>=0&&s<60)?s:0;
}
int Time::getHour(){  //returns hour
    return hour;
}
int Time::getMinute(){ //returns minute
    return minute;
}
int Time::getSecond(){ //returns second
    return second;
}

void Time::printUniversal(){  //it will display time as universal time
    std::cout<<std::setfill('0')<<std::setw(2)<<getHour()<<":"<<std::setw(2)<<getMinute()<<":"<<std::setw(2)<<getSecond();
}

void Time::printStandard(){ //it will display time as standard time
    std::cout<<((getHour()==0||getHour()==12)?12:getHour()%12)<<":"<<std::setfill('0')<<std::setw(2)<<getMinute()<<":"<<std::setw(2)<<getSecond()<<(hour<12?"AM":"PM");
}
int Time::tick(){  //this function will increment the second and it show differences in hour and minute if second and minutate validation range exceed
    second++;
    if(second==60){
        minute++;
        second=0;
        if(minute==60){
            hour++;
            minute=0;
            if(hour==24)
            hour=0;
        }
    }
    return second;
}