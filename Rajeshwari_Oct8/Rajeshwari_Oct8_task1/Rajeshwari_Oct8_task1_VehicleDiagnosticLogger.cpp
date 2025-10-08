#include "Rajeshwari_Oct8_task1_VehicleDiagnosticLogger.h"
// function to convert SeverityLevel enum values to readable strings
std::string severityToString(SeverityLevel level) {
    switch (level) {
        case SeverityLevel::Low: return "Low";
        case SeverityLevel::Medium: return "Medium";
        case SeverityLevel::High: return "High";
        case SeverityLevel::Critical: return "Critical";
        default: return "";
    }
}
SensorReading::SensorReading(std::string name,double val,SeverityLevel sl)//constructor
:
sensorName(name),
value(val),
severity(sl)
{
    setName(name);
    setValue(val);
    setSeverityLevel(sl);
}
//set and get functions
void SensorReading::setName(std::string name){
    sensorName=name;
}
void SensorReading::setValue(double val){
    value=val;
}
void SensorReading:: setSeverityLevel(SeverityLevel sl){
    severity=sl;
}
std::string SensorReading::getName() const{
    return sensorName;
}
double SensorReading::getValue() const{
    return value;
}
SeverityLevel SensorReading::getSeverityLevel() const{
    return severity;
}
//method to display the reading 
void SensorReading::display() const{
    std::cout<<"sensor name : "<<getName()<<"\n"<<"value : "<<getValue()<<"\n"<<"SeverityLevel : "<<severityToString(getSeverityLevel())<<"\n";
}
//Method to add a new sensor reading
void DiagnosticReport::addSensor(const SensorReading& reading) {
        readings.push_back(reading);
}
//Method to display all readings 
void DiagnosticReport::displayReadings(){
    if(readings.empty()) return;
    for (const auto& reading : readings) {
            reading.display();
        }
}
//Method to count how many readings are of a given severity or higher 
int DiagnosticReport::count(){
    int c=0;
    for(const auto& reading : readings){
        if(static_cast<int>(reading.getSeverityLevel()) >= static_cast<int>(SeverityLevel::High)){
            c++;
        }
    }
    return c;
}
