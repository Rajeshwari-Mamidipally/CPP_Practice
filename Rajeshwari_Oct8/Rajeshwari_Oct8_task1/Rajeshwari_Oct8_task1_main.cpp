#include "Rajeshwari_Oct8_task1_VehicleDiagnosticLogger.h"
int main(){
    DiagnosticReport obj;  //Create a DiagnosticReport object. 
    //adding sample readings to report
    obj.addSensor(SensorReading("EngineTemp", 105, SeverityLevel::High));
    obj.addSensor(SensorReading("OilPressure", 20, SeverityLevel::Medium));
    obj.addSensor(SensorReading("BrakeFluidLevel", 5, SeverityLevel::Low));
    obj.addSensor(SensorReading("BatteryVoltage", 12.5, SeverityLevel::Critical));
    obj.displayReadings();   // Display all sensor readings.
    //Count and display how many readings have severity High or Critical. 
    std::cout<<"Number of readings with severity High or critical: "<<obj.count()<<"\n";
    return 0;

}