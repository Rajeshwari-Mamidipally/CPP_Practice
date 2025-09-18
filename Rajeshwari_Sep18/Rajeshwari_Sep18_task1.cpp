#include<iostream>
class VehicleStatus
{
private:
    int num_wheels;
    float* wheel_speed;
    int num_temps;
    float* engine_temp;
public:
    VehicleStatus(int no_of_wheels,float* speed,int no_of_temps,float* engine_temps) //constructor
    :
    num_wheels(no_of_wheels),
    num_temps(no_of_temps)
    {
        wheel_speed=new float[num_wheels];
        engine_temp=new float[num_temps];
        for (int i = 0; i < num_wheels; ++i) {
            wheel_speed[i] = speed[i];
        }
        for (int i = 0; i < num_temps; ++i) {
            engine_temp[i] = engine_temps[i];
        }

    }

    ~VehicleStatus(){           //destructor
        delete[] wheel_speed;
        wheel_speed=nullptr;
        delete[] engine_temp;
        engine_temp=nullptr;
    }
    //getter functions
    int getWheels() const{return num_wheels;}
    int getTemps() const{return num_temps;}
     float getWheelSpeed(int index) const { return wheel_speed[index]; }
    float getEngineTemp(int index) const { return engine_temp[index]; }
   
   

    float averageWheelSpeed() const{   //calculating average of wheels speed
        float avg=0;
        for(int i=0;i<num_wheels;i++){
            avg+=wheel_speed[i];
        }
        return avg/num_wheels;

    }
    float  maxEngineTemp() const{       //finding max temperature
        float max=engine_temp[0];
        for(int i=1;i<num_temps;i++){
            if(max<engine_temp[i]){
                max=engine_temp[i];
            }
        }
        return max;
    }
    bool isWheelSpeedHigher(const VehicleStatus& other) const{
        float maxSpeedThis = wheel_speed[0];
        for (int i = 1; i < num_wheels; i++)
        {
            if (wheel_speed[i] > maxSpeedThis)
                maxSpeedThis = wheel_speed[i];
        }

        float maxSpeedOther = other.wheel_speed[0];
        for (int i = 1; i < other.num_wheels; i++)
        {
            if (other.wheel_speed[i] > maxSpeedOther)
                maxSpeedOther = other.wheel_speed[i];
        }

        return maxSpeedThis > maxSpeedOther;
    }
    friend void printVehicleStatus(const VehicleStatus& vs);
};
//global functions

void printVehicleStatus(const VehicleStatus& vs){
    std::cout<<"Displaying wheel speeds\n";
    for(int i=0;i<vs.getWheels();i++){
        std::cout<<"speed "<<i<<" : "<<vs.getWheelSpeed(i)<<'\n';
    }
    std::cout<<"Displaying engine temperatures\n";
    for(int i=0;i<vs.getTemps();i++){
        std::cout<<"temperature "<<i<<" : "<<vs.getEngineTemp(i)<<'\n';
    }
}
bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2){
    return vs1.isWheelSpeedHigher(vs2);
}

int main(){
    int num_wheels = 4;
    float wheel_speed1[] = {55.5f, 56.6f, 57.2f, 55.9f};
    int num_temps = 2;
    float engine_temp1[] = {90.5f, 88.9f};

    float wheel_speed2[] = {50.0f, 51.2f, 49.8f, 50.4f};
    float engine_temp2[] = {92.0f, 89.5f};
    
    VehicleStatus vehicle1(num_wheels, wheel_speed1, num_temps, engine_temp1);
    VehicleStatus vehicle2(num_wheels, wheel_speed2, num_temps, engine_temp2);
    printVehicleStatus(vehicle1);
    printVehicleStatus(vehicle2);
    std::cout << "\nComparisons:\n";
    if (vehicle1.isWheelSpeedHigher(vehicle2)) {
    std::cout << "Vehicle 1 has higher maximum wheel speed than Vehicle 2.\n";
    } else {
    std::cout << "Vehicle 2 has higher maximum wheel speed than Vehicle 1.\n";
    }

    if (compareWheelSpeedGlobal(vehicle1, vehicle2)) {
        std::cout << "Global comparison: Vehicle 1 > Vehicle 2\n";
    } else {
        std::cout << "Global comparison: Vehicle 2 >= Vehicle 1\n";
    }
    return 0;

}


