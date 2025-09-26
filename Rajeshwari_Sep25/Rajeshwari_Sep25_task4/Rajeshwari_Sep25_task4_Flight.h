#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>
using namespace std;

enum FlightStatus {
    PARKED,
    TAXIING,
    WAITING_FOR_TAKEOFF,
    TAKING_OFF,
    CLIMBING,
    CRUISING,
    CHANGING_ALTITUDE,
    DESCENDING,
    LANDING,
    LANDED
};

class Flight {
private:
    string airline;
    string flightNumber;
    string makeModel;
    int currentSpeed;
    int currentAltitude;
    int newAltitude;
    string direction;
    string origin;
    string destination;
    string departureTime;
    string estimatedArrivalTime;
    FlightStatus status;

public:
    Flight(string airline, string flightNumber, string makeModel,int currentSpeed, int currentAltitude, string direction, string origin, string destination, string departureTime, string estimatedArrivalTime, FlightStatus status);

    // Setters and Getters
    void setCurrentSpeed(int speed);
    int getCurrentSpeed() const;
    void setCurrentAltitude(int alt);
    int getCurrentAltitude() const;
    void setStatus(FlightStatus newStatus);
    FlightStatus getStatus() const;

    // Behaviors
    void changeAltitude(int newAlt);
    void reduceSpeed(int speedReduction);
    void beginLandingApproach();

    string toString() const;
    string getStatusString() const;
};

#endif
