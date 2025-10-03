#include<iostream>
#include "Rajeshwari_Oct1_task1_HybridVehicle.h"
#include<string>
HybridVehicle::HybridVehicle(std::string modelName_,float electricKm_,float gasolineKm_,float gasolineUsed_) //constructor
:
modelName(modelName_),
electricKm(electricKm_),
gasolineKm(gasolineKm_),
gasolineUsed(gasolineUsed_)
{
    trips = new int[10];
    tripCount = 0;
    
}
HybridVehicle::HybridVehicle(const HybridVehicle& other) //copy constructor
: 
modelName(other.modelName),
electricKm(other.electricKm),
gasolineKm(other.gasolineKm),
gasolineUsed(other.gasolineUsed),
tripCount(other.tripCount)
{
    trips=new int[10];
    for (int i = 0; i < 10; i++) trips[i] = other.trips[i];
}
HybridVehicle::~HybridVehicle() { //destructor
    delete[] trips;
}
HybridVehicle& HybridVehicle::operator=(const HybridVehicle &r) { //operator= (Deep copy of trips and usage)
    if (this != &r) {
        modelName = r.modelName;
        electricKm = r.electricKm;
        gasolineKm = r.gasolineKm;
        gasolineUsed = r.gasolineUsed;
        tripCount = r.tripCount;
        delete[] trips;
        trips = new int[10];
        for (int i = 0; i < 10; i++) trips[i] = r.trips[i];
    }
    return *this;
}
HybridVehicle HybridVehicle::operator+(const HybridVehicle& r) const { //operator+ (Combine two vehicles’ usage )
    HybridVehicle temp(modelName+r.modelName, electricKm + r.electricKm, gasolineKm + r.gasolineKm, gasolineUsed + r.gasolineUsed);
    return temp;
}
bool HybridVehicle::operator==(const HybridVehicle& r) const { //operator== :Compare efficiency 
    return (float)(*this) == (float)r;  // compare efficiencies
}
HybridVehicle& HybridVehicle::operator++() { //operator++ (Increment trip count and add dummy trip )
    if (tripCount < 10) {
        trips[tripCount++] = 10; // add dummy trip of 10 km
    }
    return *this;
}
int& HybridVehicle::operator[](int index) {//operator[] (Access trip distance by index )
    return trips[index];
}
float HybridVehicle::operator()() const {//operator() it returns total distance
    return electricKm + gasolineKm;
}
HybridVehicle::operator float() const {
    return gasolineKm / gasolineUsed; // convert efficiency km/L
}
std::ostream& operator<<(std::ostream &out, const HybridVehicle &r) {  //Print vehicle details 
    out << r.modelName<<","<<r.electricKm<<","<<r.gasolineKm<<","<<r.gasolineUsed;
    return out;

}