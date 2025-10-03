#include<iostream>
#include "Rajeshwari_Oct1_task1_HybridVehicle.h"
#include<string>
int main(){
    HybridVehicle v1("Prius", 120.5, 80.0, 4.5);
    HybridVehicle v2("Volt", 100.0, 90.0, 5.0);
    v1[0] = 50; v1[1] = 60;
    v2[0] = 70; v2[1] = 40;
    std::cout<<"v1 : "<<v1<<'\n';
    std::cout<<"v2 : "<<v2<<'\n';
    HybridVehicle v3 = v1 + v2;
    std::cout << "After adding two objects v1 and  v2: " << v3 <<std::endl;

    std::cout << "Efficiency compare: " << (v1 == v2 ? "Equal" : "Not equal") <<std::endl;

    ++v1;//incrementing v1 trip count 
    std::cout << "After ++, v1 total distance: " << v1() <<std::endl;

    std::cout << "Trip[0] of v1: " << v1[0] <<std::endl;

    std::cout << "Efficiency of v1: " << float(v1) << " km/L" <<std::endl;

    HybridVehicle v4 = v1; // assignment
    std::cout << "v4 (copy of v1): " << v4 <<std::endl;

    return 0;
}



