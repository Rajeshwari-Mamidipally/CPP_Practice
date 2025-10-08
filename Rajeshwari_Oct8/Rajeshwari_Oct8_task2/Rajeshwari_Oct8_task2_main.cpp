#include "Rajeshwari_Oct8_task2_VehicleDiagnosticLogger.h"
int main(){
    DiagnosticReport obj;  //Create a DiagnosticReport object. 
    //adding sample readings
    obj.addSensor(SensorReading("EngineTemp", 105, SeverityLevel::High));
    obj.addSensor(SensorReading("OilPressure", 20, SeverityLevel::Medium));
    obj.addSensor(SensorReading("BrakeFluidLevel", 5, SeverityLevel::Low));
    obj.addSensor(SensorReading("BatteryVoltage", 12.5, SeverityLevel::Critical));
    obj.severityDistributionMap(); //Display the severity distribution map. 
    obj.displayReadings(); //displaying readings before sorting
    obj.sortBySeverityDescending();//Sort and display readings by severity. 
    std::cout<<"Displaying after sorting reading : \n";
    obj.displayReadings(); //displaying readings after sorting
    int countCritical=0;
    //Filter and display only Critical readings. 
    SensorReading* criticalReadings = obj.filterBySeverity(SeverityLevel::Critical, countCritical);
    if (criticalReadings) {
        std::cout << "Critical Readings:\n";
        for (int i = 0; i < countCritical; i++) {
           criticalReadings[i].display();
        }
        delete[] criticalReadings; // free memory
    }
    //Search for a specific sensor (e.g., "BrakeFluidLevel") and display its details. 
    SensorReading* brakeSensor = obj.findReadingByName("BrakeFluidLevel");
    if (brakeSensor) {
        brakeSensor->display();
    }
    std::cout<<"Number of readings with severity High or critical: "<<obj.count()<<"\n";  // Count and display how many readings have severity High or Critical. 

    
    return 0;

}