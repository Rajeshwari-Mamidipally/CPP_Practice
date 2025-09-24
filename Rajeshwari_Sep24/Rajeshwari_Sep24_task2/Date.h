#ifndef DATE_H
#define DATE_H
class Date{
    public:
    Date(int=1,int=1,int=2000);//default constructor
    //member functions
    void print();
    void nextDay();
    int getDaysInMonth(int,int)const;
    bool isLeapYear(int)const;
    private:
    int month;
    int day;
    int year;
};
#endif