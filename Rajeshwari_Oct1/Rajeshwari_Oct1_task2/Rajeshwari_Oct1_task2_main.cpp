#include<iostream>
#include "Rajeshwari_Oct1_task2_BatteryMonitor.h"
int main(){
    BatteryMonitor s1("SCT101", 300, 4.0, 5.0, true, 3); 
    BatteryMonitor s2("SCT202", 150, 3.5, 5.0, true, 2);
    s1[0] = 12; s1[1] = 18; s1[2] = 25; 
    s2[0] = 10; s2[1] = 15; 
    std::cout<<"s1 : "<<s1<<'\n';
    std::cout<<"s2 : "<<s2<<'\n';
    std::cout<<"compare battery health : "<<(s1>s2 ? "s1 has better health\n":"s2 has better health\n")<<"\n";
    s1+=50;
    std::cout<<"s1 after 50 cycles : "<<s1<<'\n';


    std::cout<<"checking inactive status : "<<(!s1?"yes":"no")<<'\n';
    BatteryMonitor s3=s1;
    s3[0]=49;
    std::cout<<"s3 (copy of s1) and modified s3[0] as 49 : "<<s3<<'\n';
    return 0;

}