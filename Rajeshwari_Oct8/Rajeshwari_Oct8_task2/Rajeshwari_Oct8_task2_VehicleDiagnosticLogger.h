#ifndef RAJESHWARI_OCT8_TASK2_VEHICLEDIAGNOSTICLOGGER_H
#define RAJESHWARI_OCT8_TASK2_VEHICLEDIAGNOSTICLOGGER_H
#include<iostream>
#include<string>
#include<vector>
#include<map>
//enum
enum class SeverityLevel{
    Low,
    Medium,
    High,
    Critical

};
//convert SeverityLevel enum values to readable strings
std::string severityToString(SeverityLevel level); 
class SensorReading{
    private:
    std::string sensorName;
    double value;
    SeverityLevel severity;
    public:
    SensorReading() : sensorName(""), value(0.0), severity(SeverityLevel::Low) {}//default constructor
    SensorReading(std::string senorName,double value,SeverityLevel severity);//constructor
    ~SensorReading();//destructor
    //set and get functions
    void setName(std::string sensorName);
    void setValue(double value);
    void setSeverityLevel(SeverityLevel severity);
    std::string getName() const;
    double getValue()const;
    SeverityLevel getSeverityLevel() const;
    void display() const; //displaying readings


};
class DiagnosticReport {
    private:
    std::vector<SensorReading> readings;
    public:
    SensorReading* filterBySeverity(SeverityLevel level, int& count)const; //filtering according to the severity level
    void sortBySeverityDescending(); //sorting according to severity in descending order
    void severityDistributionMap()const;//severity distribution map
    SensorReading* findReadingByName(const std::string& name);//returns readings according to name
    void addSensor(const SensorReading& ); //adding readings
    void displayReadings()const; ///displaying all readings
    int count(); //returns count of readings of critical and high


};
#endif