#ifndef TIME_H
#define TIME_H
class Time{
    public:
    Time(int=0,int=0,int=0); //constructor
    //set functions
    bool setTime(int,int,int); //set time
    bool setHour(int);//sets hour
    bool setMinute(int);//sets minute
    bool setSecond(int);//sets second
    //get functions
    int getHour() const;//returns hour 
    int getMinute() const;//returns minute
    int getSecond()const;//returns second
    //member functions
    void printUniversal() const;//displays universal time
    void printStandard() const;//displays standard time


    private:
    int hour;
    int minute;
    int second;
};
#endif