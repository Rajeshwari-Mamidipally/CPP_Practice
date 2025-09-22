#include <iostream>
#include "HealthProfile.h"
using namespace std;

// Constructor
HealthProfile::HealthProfile(string fName, string lName, string gen,
                             int day, int month, int year,
                             double h, double w) {
    firstName = fName;
    lastName = lName;
    gender = gen;
    birthDay = day;
    birthMonth = month;
    birthYear = year;
    height = h;
    weight = w;
}

// Setters
void HealthProfile::setFirstName(string fName) { firstName = fName; }
void HealthProfile::setLastName(string lName) { lastName = lName; }
void HealthProfile::setGender(string gen) { gender = gen; }
void HealthProfile::setBirthDay(int day) { birthDay = day; }
void HealthProfile::setBirthMonth(int month) { birthMonth = month; }
void HealthProfile::setBirthYear(int year) { birthYear = year; }
void HealthProfile::setHeight(double h) { height = h; }
void HealthProfile::setWeight(double w) { weight = w; }

// Getters
string HealthProfile::getFirstName() const { return firstName; }
string HealthProfile::getLastName() const { return lastName; }
string HealthProfile::getGender() const { return gender; }
int HealthProfile::getBirthDay() const { return birthDay; }
int HealthProfile::getBirthMonth() const { return birthMonth; }
int HealthProfile::getBirthYear() const { return birthYear; }
double HealthProfile::getHeight() const { return height; }
double HealthProfile::getWeight() const { return weight; }

// Function to calculate age
int HealthProfile::getAge() {
    int currentDay, currentMonth, currentYear;
    cout << "\nEnter current day: ";
    cin >> currentDay;
    cout << "Enter current month: ";
    cin >> currentMonth;
    cout << "Enter current year: ";
    cin >> currentYear;

    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

// Maximum heart rate
int HealthProfile::getMaximumHeartRate() {
    int age = getAge();
    return 220 - age;
}

// Target heart rate range
void HealthProfile::getTargetHeartRate() {
    int maxHR = getMaximumHeartRate();
    double lower = maxHR * 0.50;
    double upper = maxHR * 0.85;
    cout << "Target Heart Rate Range: " << lower << " - " << upper << " bpm" << endl;
}

// BMI calculation
double HealthProfile::getBMI() {
    return (weight * 703) / (height * height); // BMI formula in pounds/inches
}

// Display BMI chart
void HealthProfile::displayBMIChart() {
    cout << "\nBMI VALUES" << endl;
    cout << "Underweight: less than 18.5" << endl;
    cout << "Normal:      between 18.5 and 24.9" << endl;
    cout << "Overweight:  between 25 and 29.9" << endl;
    cout << "Obese:       30 or greater" << endl;
}
