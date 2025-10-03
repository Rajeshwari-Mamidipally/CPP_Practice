#include<iostream>
#include "Rajeshwari_Oct1_task2_BatteryMonitor.h"
#include<string>
BatteryMonitor::BatteryMonitor(std::string scooterID_,int chargeCycles_,float batteryCapacity_,float originalCapacity_,bool isActive_,int tripCount_)
:
scooterID(scooterID_),
chargeCycles(chargeCycles_),
batteryCapacity(batteryCapacity_),
originalCapacity(originalCapacity_),
isActive(isActive_),
tripCount(tripCount_){
    tripDistances=new int[tripCount];
    for (int i = 0; i < tripCount; i++)
     tripDistances[i] = 0;

}
BatteryMonitor::BatteryMonitor(const BatteryMonitor& other)
:
scooterID(other.scooterID),
chargeCycles(other.chargeCycles),
batteryCapacity(other.batteryCapacity),
originalCapacity(other.originalCapacity),
isActive(other.isActive),
tripCount(other.tripCount){
    tripDistances=new int[tripCount];
    for(int i=0;i<tripCount;i++){
        tripDistances[i]=other.tripDistances[i];
    }
}
BatteryMonitor::~BatteryMonitor(){
    delete[]  tripDistances;
}
BatteryMonitor& BatteryMonitor::operator=(const BatteryMonitor &r){
    if(this!=&r){
        scooterID=r.scooterID;
        chargeCycles=r.chargeCycles;
        batteryCapacity=r.batteryCapacity;
        originalCapacity=r.originalCapacity;
        isActive=r.isActive;
        tripCount=r.tripCount;
        delete[] tripDistances;
        tripDistances=new int[tripCount];
        for(int i=0;i<tripCount;i++)
        tripDistances[i]=r.tripDistances[i];
    }
    return *this;
}
bool BatteryMonitor::operator>(const BatteryMonitor &r)const{
    return (batteryCapacity/originalCapacity)>(r.batteryCapacity/r.originalCapacity);
}
bool BatteryMonitor::operator<(const BatteryMonitor &r)const{
    return (batteryCapacity/originalCapacity)<(r.batteryCapacity/r.originalCapacity);
}
BatteryMonitor& BatteryMonitor::operator+=(int cycles){
    chargeCycles += cycles;
    batteryCapacity -= (0.001f * cycles * originalCapacity); // degrade 0.1% per cycle
    if (batteryCapacity < 0) batteryCapacity = 0;
    return *this;
    
}
int& BatteryMonitor::operator[](int i){
    return tripDistances[i];
}
bool BatteryMonitor::operator!() const{
    return !isActive;
}
std::ostream& operator<<(std::ostream &out, const BatteryMonitor &r){
    out<<r.scooterID<<","<<r.chargeCycles<<","<<r.batteryCapacity<<","<<r.originalCapacity<<","<<r.isActive<<","<<r.tripCount;
    return out;
}