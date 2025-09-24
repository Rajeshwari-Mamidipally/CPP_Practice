#include<iostream>
#include "Time.h"
int main(){
    Time t(25,59,55); //creating object t
    std::cout << "Testing tick() function:\n";
    std::cout << "Starting time: ";
    std::cout<<"\nuniversal time\n";
    t.printUniversal();//printing universal time
    std::cout<<"\nstandard time\n";
    t.printStandard(); //printing standard time
    std::cout << "\n\n";

    // Loop to demonstrate increment
    for (int i = 0; i < 10; ++i) {
        t.printStandard();
        std::cout <<std::endl;
        t.tick(); // Increment time by one second
    }
    return 0;

   
}