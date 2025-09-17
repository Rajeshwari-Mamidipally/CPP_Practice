#include<iostream>
#include <cstdint>
#include <cfloat> 
class  TrackedVehicle
{
private:
    uint32_t vehicle_id;
    float speed;
    float distance;
    static float min_recorded_distance;
    static int vehicle_count;
public:
     TrackedVehicle(uint32_t vehicleId,float s,float d)
     : vehicle_id(vehicleId),
     speed(s),
     distance(d)
     {
        vehicle_count++;
        if (d < min_recorded_distance) {
            min_recorded_distance = d;
        }
     }
    ~ TrackedVehicle(){
        vehicle_count--;
    }

    uint32_t getVehicleId() const{return vehicle_id;}
    float getSpeed() const{return speed;}
    float getDistance() const{return distance;}
    static float getMinRecordedDistance(){
        return min_recorded_distance;

    }
    static int getVehicleCount(){
        return vehicle_count;
    }


    void display() const{
        std::cout<<"VehicleId : "<<vehicle_id<<"\t\t";
        std::cout<<"Vehicle Speed : "<<speed<<" km/h\t\t";
        std::cout<<"Vehicle Distance : "<<distance<<" m\n";
    }
    const TrackedVehicle* compareDistance(const TrackedVehicle& other) const {
        if (other.distance < this->distance) {
            return &other; 
        } else {
            return this;   
        }
    }
   
};
float TrackedVehicle::min_recorded_distance = FLT_MAX;
int TrackedVehicle::vehicle_count = 0;

void findLeadVehicle(TrackedVehicle* arr,uint32_t size, const TrackedVehicle*& lead){
    if (arr == nullptr || size == 0) {
        lead = nullptr; 
        return;
    }

    lead = &arr[0]; 

    for (uint32_t i = 1; i < size; ++i) {
        if (arr[i].getDistance() < lead->getDistance()) {
            lead = &arr[i];
        }
    }
 }
void printTrackedVehicle(const TrackedVehicle& vehicle) {
    vehicle.display();
 }
void printLeadVehicle(const TrackedVehicle* lead){
    if (lead != nullptr) {
        std::cout<<"Lead Vehicle details"<<'\n';
        lead->display();    
    }
    else {
        std::cout << "\nLead Vehicle: None found\n";
    }
}

int main() {
    
    TrackedVehicle* vehicles = new TrackedVehicle[4]{
        {501, 80.0f, 60.0f},
        {502, 78.0f, 45.0f},
        {503, 85.0f, 100.0f},
        {504, 76.0f, 40.0f}
    };
    std::cout << "\nTracked Vehicles:\n";
    for (int i = 0; i < 4; ++i) {
        printTrackedVehicle(vehicles[i]);
    }
    const TrackedVehicle* lead = nullptr;
    findLeadVehicle(vehicles, 4, lead);

    printLeadVehicle(lead);

    std::cout << "Minimum Recorded Distance: "<< TrackedVehicle::getMinRecordedDistance() << " m\n";
    std::cout << "Total Vehicles Tracked: "<< TrackedVehicle::getVehicleCount() << std::endl;

    delete[] vehicles;

    std::cout << "\nMemory deallocated successfully.\n";
    return 0;
    
}

