#include <iostream>
#include "HeartRates.h"
int main() {
    std::string firstName, lastName;
    int day, month, year;

    // Get user input
    std::cout << "Enter first name: ";
    std::cin >> firstName;

    std::cout << "Enter last name: ";
    std::cin >> lastName;

    std::cout << "Enter birth day (DD): ";
    std::cin >> day;

    std::cout << "Enter birth month (MM): ";
    std::cin >> month;

    std::cout << "Enter birth year (YYYY): ";
    std::cin >> year;
    HeartRates person(firstName, lastName, day, month, year);   // Creating HeartRates object
    // Display information
    std::cout << "\n--- Personal Information ---" <<std::endl;
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() <<std::endl;
    std::cout << "Date of Birth: " << person.getBirthDay() << "-" << person.getBirthMonth() << "-" << person.getBirthYear() <<std::endl;
    int age = person.getAge();
    std::cout << "Age: " << age << " years" <<std::endl;
    int maxHR = 220 - age;
    std::cout << "Maximum Heart Rate: " << maxHR << " bpm" <<std::endl;
    person.getTargetHeartRate();

    return 0;
}
