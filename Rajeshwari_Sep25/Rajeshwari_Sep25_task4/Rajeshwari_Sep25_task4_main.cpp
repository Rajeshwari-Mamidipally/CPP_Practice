#include <iostream>
#include "Flight.h"
using namespace std;

int main() {
    cout << "AirTrafficControlSimulator\n\n";

    // Create three flight objects in different states
    Flight flight1("Delta", "DL101", "Boeing 737", 0, 0,"N/A", "BOS", "LAX", "08:00", "11:00", PARKED);

    Flight flight2("American Airlines", "AA202", "Airbus A320", 20, 0,"North", "JFK", "MIA", "09:00", "12:00", WAITING_FOR_TAKEOFF);

    Flight flight3("United", "UA303", "Boeing 777", 300, 20000,"West", "ORD", "SFO", "07:30", "11:30", CRUISING);

    
    cout << flight1.toString() << endl; 
    flight1.changeAltitude(5000);
    flight1.reduceSpeed(10);
    cout << endl;

    cout << flight2.toString() << endl;
    flight2.changeAltitude(10000);
    flight2.beginLandingApproach();
    cout << endl;

    cout << flight3.toString() << endl;
    flight3.changeAltitude(25000);
    flight3.reduceSpeed(50);
    flight3.beginLandingApproach();
    cout << endl;

    return 0;
}
