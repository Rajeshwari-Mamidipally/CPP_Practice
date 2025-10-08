#ifndef RAJESHWARI_OCT8_TASK1_VEHICLEDIAGNOSTICLOGGER_H
#define RAJESHWARI_OCT8_TASK1_VEHICLEDIAGNOSTICLOGGER_H
#include<iostream>
#include<string>
#include<vector>
//enum
enum class SeverityLevel{
    Low,
    Medium,
    High,
    Critical

};
// function to convert SeverityLevel enum values to readable strings
std::string severityToString(SeverityLevel level); 
class SensorReading{
    private:
    std::string sensorName;
    double value;
    SeverityLevel severity;
    public:
    SensorReading(std::string senorName,double value,SeverityLevel severity); //constructor
    //set and get functions
    void setName(std::string sensorName);
    void setValue(double value);
    void setSeverityLevel(SeverityLevel severity);
    std::string getName() const;
    double getValue()const;
    SeverityLevel getSeverityLevel() const;
    void display() const;  //A method to display the reading 


};
class DiagnosticReport {
    private:
    std::vector<SensorReading> readings;
    public:
    void addSensor(const SensorReading& );  //Method to add a new sensor reading
    void displayReadings();  //Method to display all readings 
    int count();  //Method to count how many readings are of a given severity or higher 
};
#endif