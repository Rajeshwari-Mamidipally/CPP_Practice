#include<iostream>
#include "Time.h"
int main(){
    Time t; //creating object t
    int hour, minute, second;
    std::cout << "Enter hour, minute, and second: ";
    std::cin >> hour >> minute >> second;
    // Attempt to set time
    if (!t.setTime(hour, minute, second)) {
        std::cout << "\nError: Invalid time values provided!\n";
        if (!(hour >= 0 && hour < 24))
            std::cout << "Invalid hour: " << hour << " (must be 0-23)\n";
        if (!(minute >= 0 && minute < 60))
            std::cout << "Invalid minute: " << minute << " (must be 0-59)\n";
        if (!(second >= 0 && second < 60))
            std::cout << "Invalid second: " << second << " (must be 0-59)\n";
    } else {
        std::cout << "\nUniversal time: ";
        t.printUniversal();

        std::cout << "\nStandard time: ";
        t.printStandard();
    }
    return 0;

   
}
