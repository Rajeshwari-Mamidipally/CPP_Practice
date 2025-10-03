#include "Rajeshwari_Sep25_task4_Flight.h"

// Constructor
Flight::Flight(string airline, string flightNumber, string makeModel,int currentSpeed, int currentAltitude,string direction, string origin, string destination,string departureTime, string estimatedArrivalTime, FlightStatus status)
    : airline(airline), flightNumber(flightNumber), makeModel(makeModel),
      currentSpeed(currentSpeed), currentAltitude(currentAltitude),
      newAltitude(currentAltitude),
      direction(direction), origin(origin), destination(destination),
      departureTime(departureTime), estimatedArrivalTime(estimatedArrivalTime),
      status(status) {}

// Setters/Getters
void Flight::setCurrentSpeed(int speed) { currentSpeed = speed; }
int Flight::getCurrentSpeed() const { return currentSpeed; }
void Flight::setCurrentAltitude(int alt) { currentAltitude = alt; }
int Flight::getCurrentAltitude() const { return currentAltitude; }
void Flight::setStatus(FlightStatus newStatus) { status = newStatus; }
FlightStatus Flight::getStatus() const { return status; }

// Change Altitude
void Flight::changeAltitude(int newAlt) {//here altitude of the flight is changing to new altitude
    cout << airline << " " << flightNumber << " changing altitude from "<< currentAltitude << " to " << newAlt << " feet.\n";
    status = CHANGING_ALTITUDE;//changing status as changing altitude
    newAltitude = newAlt;
}

// Reduce Speed
void Flight::reduceSpeed(int speedReduction) {//here current speed is reduced by the speedreduction
    currentSpeed -= speedReduction;
    if (currentSpeed < 0) currentSpeed = 0;//if current speed is less than 0 than current speed will assign to 0
    cout << airline << " " << flightNumber << " reducing speed by "<< speedReduction << " knots. New speed: " << currentSpeed << " knots.\n";
}

// Begin Landing Approach
void Flight::beginLandingApproach() {
    status = DESCENDING;//when flight is begin landing approach then status will changes to desending
    cout << airline << " " << flightNumber << " beginning landing approach.\n";
}

// Convert status enum to string
string Flight::getStatusString() const { 
    switch (status) {
        case PARKED: return "Parked";
        case TAXIING: return "Taxiing";
        case WAITING_FOR_TAKEOFF: return "Waiting for Takeoff";
        case TAKING_OFF: return "Taking Off";
        case CLIMBING: return "Climbing";
        case CRUISING: return "Cruising";
        case CHANGING_ALTITUDE: return "Changing Altitude";
        case DESCENDING: return "Descending";
        case LANDING: return "Landing";
        case LANDED: return "Landed";
        default: return "Unknown";
    }
}

// Return string representation of Flight
string Flight::toString() const {
    return airline + " " + flightNumber + " [" + makeModel + "]\n"
           "Status: " + getStatusString() + "\n"
           "Speed: " + to_string(currentSpeed) + " knots\n"
           "Altitude: " + to_string(currentAltitude) + " feet\n"
           "Target Altitude: " + to_string(newAltitude) + " feet\n"
           "Direction: " + direction + "\n"
           "From: " + origin + " To: " + destination + "\n"
           "Departure: " + departureTime + " Arrival: " + estimatedArrivalTime + "\n";
}

