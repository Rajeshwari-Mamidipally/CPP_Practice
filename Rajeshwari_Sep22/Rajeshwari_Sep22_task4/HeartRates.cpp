#include<iostream>
#include "HeartRates.h"
HeartRates::HeartRates(std::string fname,std::string lname,int d,int m,int y){
    setFirstName(fname);
    setLastName(lname);
    setBirthDay(d);
    setBirthMonth(m);
    setBirthYear(y);

}
//setters
void HeartRates::setFirstName(std::string fname){
    FirstName=fname;
}
void HeartRates::setLastName(std::string lname){
    LastName=lname;
}
void HeartRates::setBirthDay(int d){
    BirthDay=d;
}
void HeartRates::setBirthMonth(int m){
    BirthMonth=m;
}
void HeartRates::setBirthYear(int y){
    BirthYear=y;
}
//getters
std::string HeartRates::getFirstName(){
    return FirstName;
}
std::string HeartRates::getLastName(){
    return LastName;
}
int HeartRates::getBirthDay(){
    return BirthDay;
}
int HeartRates::getBirthMonth(){
    return BirthMonth;
}
int HeartRates::getBirthYear(){
    return BirthYear;
}
// Function to calculate age
int HeartRates::getAge() {
    int currentDay, currentMonth, currentYear;
    std::cout << "\nEnter current day: ";
    std::cin >> currentDay;
    std::cout << "Enter current month: ";
    std::cin >> currentMonth;
    std::cout << "Enter current year: ";
    std::cin >> currentYear;

    int age = currentYear - BirthYear;

    // If the birthday hasn't occurred yet this year
    if (currentMonth < BirthMonth || (currentMonth == BirthMonth && currentDay < BirthDay)) {
        age--;
    }
    return age;
}
int HeartRates::getMaximumHeartRate() {  // Function to calculate maximum heart rate
    int age = getAge();
    return 220 - age;
}
void HeartRates::getTargetHeartRate() {  // Function to calculate and display target heart rate range
    int maxHR = getMaximumHeartRate();
    double lowerRange = maxHR * 0.50;  //50%
    double upperRange = maxHR * 0.85;  // 85%

    std::cout << "Target Heart Rate Range: " 
         << lowerRange << " - " << upperRange << " bpm" <<std::endl;
}
