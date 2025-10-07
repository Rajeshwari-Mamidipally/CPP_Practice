#include<iostream>
#include<string>
#include "Rajeshwari_Oct6_task5_Package.h"
int main(){
    Package p1("Alice", "123 Main St", "New York", "NY", "10001","Bob", "789 Park Ave", "Chicago", "IL", "60616", 10.0, 0.5); //creating object p1

    TwoDayPackage p2("Carol", "22 Elm St", "Boston", "MA", "02118","Dave", "77 Oak Rd", "Seattle", "WA", "98109", 5.0, 0.6, 2.0); //creating object p2

    OvernightPackage p3("Eve", "44 Maple Dr", "San Jose", "CA", "95112","Frank", "555 Lake St", "Denver", "CO", "80203", 8.0, 0.5, 0.2); //creating object p3

    std::cout << "Package cost: $" << p1.calculateCost() << std::endl;
    std::cout << "Two-day package cost: $" << p2.calculateCost() << std::endl;
    std::cout << "Overnight package cost: $" << p3.calculateCost() << std::endl;
    return 0;

}