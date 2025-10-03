#ifndef RAJESHWARI_OCT1_TASK2_BATTERYMONITOR_H
#define RAJESHWARI_OCT1_TASK2_BATTERYMONITOR_H
#include<string>
class BatteryMonitor{
    private:
    std::string scooterID;
    int chargeCycles;
    float batteryCapacity;
    float originalCapacity;
    bool isActive;
    int* tripDistances;
    int tripCount;
    public:
    BatteryMonitor(std::string,int,float,float,bool, int);
    BatteryMonitor(const BatteryMonitor& other);
    ~BatteryMonitor();
    BatteryMonitor& operator=(const BatteryMonitor &r);
    bool operator>(const BatteryMonitor &r)const;
    bool operator<(const BatteryMonitor &r)const;
    BatteryMonitor& operator+=(int);
    int& operator[](int);
    bool operator!()const;
    friend std::ostream& operator<<(std::ostream &out, const BatteryMonitor &r);
    

};
#endif