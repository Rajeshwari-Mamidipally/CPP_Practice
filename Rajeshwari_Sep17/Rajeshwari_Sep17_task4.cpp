#include <iostream>
#include <iomanip>
#include <limits>
// enum
enum SensorType {
    LIDAR,
    RADAR,
    CAMERA
};

// Global Function: Convert SensorType to String
const char* sensorTypeToString(SensorType t) {
    switch (t) {
        case LIDAR:  return "LIDAR";
        case RADAR:  return "RADAR";
        case CAMERA: return "CAMERA";
        default:     return "UNKNOWN";
    }
}
class SensorArray {
private:
    int sensor_id;                
    SensorType type;              
    double* temperature_readings; 
    int num_readings;             
    static double global_max_temperature;

public:
    // Constructor
    SensorArray(int id, SensorType t, const double* treadings, int nreadings)
        : sensor_id(id), type(t), num_readings(nreadings) 
    {
        temperature_readings = new double[num_readings];
        for (int i = 0; i < num_readings; ++i) {
            temperature_readings[i] = treadings[i];
            if (temperature_readings[i] > global_max_temperature) {
                global_max_temperature = temperature_readings[i];
            }
        }
    }

    // Destructor
    ~SensorArray() {
        delete[] temperature_readings;
        temperature_readings = nullptr;
    }

    // Returns maximum temperature
    double getMaxTemperature() const {
        double max_temp = temperature_readings[0];
        for (int i = 1; i < num_readings; ++i) {
            if (temperature_readings[i] > max_temp) {
                max_temp = temperature_readings[i];
            }
        }
        return max_temp;
    }

    // Print sensor info
    void printSensorInfo() const {
        std::cout << "\nSensor ID   : " << sensor_id
             << "\nType        : " << sensorTypeToString(type)
             << "\nMax Temp    : " << getMaxTemperature() << "\n";
    }
    static double getGlobalMaxTemperature() {
        return global_max_temperature;
    }
};
double SensorArray::global_max_temperature = std::numeric_limits<double>::lowest();

//  Global Functions

void printSensor(const SensorArray& s) {
    s.printSensorInfo();
}

void printAllSensors(SensorArray** arr, int size) {
    std::cout << "\n=== All Sensors Info ===\n";
    for (int i = 0; i < size; ++i) {
        printSensor(*arr[i]);
    }
}
int main() {
    double lidar_readings[]  = {35.5, 36.1, 34.9};
    double radar_readings[]  = {39.0, 38.7, 39.3};
    double camera_readings[] = {30.2, 31.0, 30.5};
    int num_sensors = 3;
    SensorArray** sensors = new SensorArray*[num_sensors];
    sensors[0] = new SensorArray(801, LIDAR, lidar_readings, 3);
    sensors[1] = new SensorArray(802, RADAR, radar_readings, 3);
    sensors[2] = new SensorArray(803, CAMERA, camera_readings, 3);
    std::cout << "\n========== Sensors Information ==========" <<std::endl;
    printAllSensors(sensors, num_sensors);
    std::cout << "\nGlobal Maximum Temperature Across All Sensors: "
         << std::fixed << std::setprecision(1)
         << SensorArray::getGlobalMaxTemperature() << "\n";

    for (int i = 0; i < num_sensors; ++i) {
    delete sensors[i]; 
    }
    delete[] sensors; 

    return 0;
}

