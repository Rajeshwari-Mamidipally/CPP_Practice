#include "Rajeshwari_Oct8_task2_VehicleDiagnosticLogger.h"
std::string severityToString(SeverityLevel level) {  // convert SeverityLevel enum values to readable strings
    switch (level) {
        case SeverityLevel::Low: return "Low";
        case SeverityLevel::Medium: return "Medium";
        case SeverityLevel::High: return "High";
        case SeverityLevel::Critical: return "Critical";
        default: return "";
    }
}
SensorReading::SensorReading(std::string name,double val,SeverityLevel sl) //constructor
:
sensorName(name),
value(val),
severity(sl)
{}
SensorReading::~SensorReading(){}//destructor
//setter and getter functions
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
void SensorReading::display() const{  // method to display the reading 
    std::cout<<"sensor name : "<<getName()<<"\n"<<"value : "<<getValue()<<"\n"<<"SeverityLevel : "<<severityToString(getSeverityLevel())<<"\n";
}
SensorReading* DiagnosticReport::filterBySeverity(SeverityLevel level, int& count)const{  //Returns all readings that match the given severity exactly. 
    count = 0;
    for (const auto& reading : readings) {
        if (reading.getSeverityLevel() == level) count++;
    }
    if (count == 0) return nullptr;
    SensorReading* filtered = new SensorReading[count];
    int idx = 0;
    for (const auto& reading : readings) {
        if (reading.getSeverityLevel() == level) filtered[idx++] = reading;
    }
    return filtered;
   
}
void DiagnosticReport::sortBySeverityDescending(){  //method to sort readings in descending order of severity
    for (int i = 0; i < readings.size(); i++) {
        for (int j = 0; j < readings.size() - i - 1;j++) {
            if (readings[j].getSeverityLevel() < readings[j + 1].getSeverityLevel()) {
                std::swap(readings[j], readings[j + 1]);
            }
        }
    }
}
void DiagnosticReport::severityDistributionMap() const{  //method to compute how many readings fall under each severity level. 
    int counts[4] = {0};

    for (const auto& reading : readings) {
        counts[static_cast<int>(reading.getSeverityLevel())]++;
    }
    std::cout << "{ ";
    std::cout << "Low: " << counts[0] << ", ";
    std::cout << "Medium: " << counts[1] << ", ";
    std::cout << "High: " << counts[2] << ", ";
    std::cout << "Critical: " << counts[3];
    std::cout << " }" << std::endl;
}
SensorReading* DiagnosticReport::findReadingByName(const std::string& name){  //method to retrieve a reading by sensor name
    for(auto& reading:readings){
        if(reading.getName()==name){
            return &reading;
        }
    }
    return nullptr;
}
void DiagnosticReport::addSensor(const SensorReading& reading) {  //Method to add a new sensor reading 
        readings.push_back(reading);
}
void DiagnosticReport::displayReadings() const{  //Method to display all readings 
    if(readings.empty()) return;
    for (const auto& reading : readings) {
            reading.display();
        }
}
int DiagnosticReport::count(){  //Method to count how many readings are of a given severity or higher
    int c=0;
    for(const auto& reading : readings){
        if(static_cast<int>(reading.getSeverityLevel()) >= static_cast<int>(SeverityLevel::High)){
            c++;
        }
    }
    return c;
}
