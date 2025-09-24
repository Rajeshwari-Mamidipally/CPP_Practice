#ifndef TIME_H
#define TIME_H
class Time{
    public:
    Time(int=0,int=0,int=0); //constructor
    //set functions
    void setTime(int,int,int); //set time
    void setHour(int);//sets hour
    void setMinute(int);//sets minute
    void setSecond(int);//sets second
    //get functions

    int getHour();//returns hour 
    int getMinute();//returns minute
    int getSecond();//returns second
    //member functions
    void printUniversal();//displays universal time
    void printStandard();//displays standard time
    int tick();//increments second

    private:
    int hour;
    int minute;
    int second;
};
#endif
