#include <iostream>
#include "HealthProfile.h"
int main() {
    std::string firstName, lastName, gender;
    int day, month, year;
    double height, weight;

    // Input
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter gender: ";
    std::cin >> gender;
    std::cout << "Enter birth day (DD): ";
    std::cin >> day;
    std::cout << "Enter birth month (MM): ";
    std::cin >> month;
    std::cout << "Enter birth year (YYYY): ";
    std::cin >> year;
    std::cout << "Enter height (in inches): ";
    std::cin >> height;
    std::cout << "Enter weight (in pounds): ";
    std::cin >> weight;

    // Creating HealthProfile object
    HealthProfile person(firstName, lastName, gender, day, month, year, height, weight);

    // Display personal info
    std::cout << "\n--- Personal Information ---" <<std::endl;
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() <<std::endl;
    std::cout << "Gender: " << person.getGender() <<std::endl;
    std::cout << "Date of Birth: " << person.getBirthDay() << "-" << person.getBirthMonth() << "-" << person.getBirthYear() <<std::endl;
    std::cout << "Height: " << person.getHeight() << " inches" <<std::endl;
    std::cout << "Weight: " << person.getWeight() << " pounds" <<std::endl;

    int age = person.getAge(); //getting age in years
    std::cout << "Age: " << age << " years" <<std::endl;

    double bmi = person.getBMI();  //calculating bmi
    std::cout << "BMI: " << bmi <<std::endl;

    int maxHR = person.getMaximumHeartRate();  //calling function to get max heart rate
    std::cout << "Maximum Heart Rate: " << maxHR << " bpm" <<std::endl;

    person.getTargetHeartRate();//function call to get trget heart rate 

    person.displayBMIChart();// Display BMI chart

    return 0;
}
