#include<iostream>
#include <cstdint> 
class Pedestrian
{
private:
    uint32_t pedestrian_id;
    float distance_from_vehicle;
public:
    Pedestrian(uint32_t pedestrianId,float distanceFromVehicle)
    :
    pedestrian_id(pedestrianId),
    distance_from_vehicle(distanceFromVehicle){}
    ~Pedestrian()=default;
    uint32_t getPedestrianId() const{return pedestrian_id;}
    float getDistanceFromVehicle() const{return distance_from_vehicle;}


    void updateDistance(float newDistance){
        distance_from_vehicle=newDistance;
    }
    float getDistance() const{
        return distance_from_vehicle;
    }
     
};

//Global functions

void findClosestPedestrian(Pedestrian* array, uint32_t size, const Pedestrian*& closest){
         if (size == 0 || array == nullptr) {
        closest = nullptr; 
        return;
    }
    closest = &array[0]; 
    for (uint32_t i = 1; i < size; ++i) {
        if (array[i].getDistance() < closest->getDistance()) {
            closest = &array[i];
        }
    }

     }

void printPedestrianInfo(const Pedestrian& ped){
    std::cout<<"pedestrian id : "<<ped.getPedestrianId()<<'\n';
    std::cout<<"Distance : "<<ped.getDistance()<<'\n';
}
void printClosestPedestrian(const Pedestrian* closest){
    if (closest != nullptr) {
        std::cout << "\nClosest Pedestrian:\n";
        printPedestrianInfo(*closest);
    } else {
        std::cout << "\nNo closest pedestrian found (pointer is null)." << std::endl;
    }
    
}
int main(){
    Pedestrian* pedestrian=new Pedestrian[3]{
        {101, 12.4f},
        {102, 8.7f},
        {103, 15.1f}
    };
    const Pedestrian* closest = nullptr;
    findClosestPedestrian(pedestrian, 3, closest);
    std::cout<<"\nPrinting all pedestrian info\n";
    for(int i=0;i<3;i++){
        printPedestrianInfo(pedestrian[i]);
    }
    printClosestPedestrian(closest);

    delete[] pedestrian;
    return 0;

}


