#ifndef  DATEANDTIME_H
#define  DATEANDTIME_H
class  DateAndTime{
    public:
    DateAndTime(int=1,int=1,int=2000,int=0,int=0,int=0); //constructor
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
    
    void printDateAndTime();//displays date and standard time
    int tick();//increments second
   
    void nextDay();
    int getDaysInMonth(int,int)const;
    bool isLeapYear(int)const;
    

    private:
    int hour;
    int minute;
    int second;
    int month;
    int day;
    int year;
};
#endif