#include<iostream>
class ObjectDistance 
{
private:
    /* data */
    float m_radar_distance;
    float m_camera_distance;  
public:
    ObjectDistance (float radar_distance,float camera_distance)
    :
    m_radar_distance(radar_distance),
    m_camera_distance(camera_distance){}

    //Getter methods 

    float GetRadarDistance() const{return m_radar_distance;}
    float GetCameraDistance() const{return m_camera_distance;}

    void adjustDistancesByValue(ObjectDistance obj) {
        obj.m_radar_distance+=5.0;
        obj.m_camera_distance+=5.0;
        std::cout<<"adjust distance by value of radar : "<<obj.m_radar_distance<<'\n';
        std::cout<<"adjust distance by value of camera : "<<obj.m_camera_distance<<'\n';

    }
    void adjustDistancesByReference(ObjectDistance& obj){
        obj.m_camera_distance+=5.0;
        obj.m_radar_distance+=5.0;
        std::cout<<"adjust distance by reference of radar : "<<obj.m_radar_distance<<'\n';
        std::cout<<"adjust distance by reference of camera : "<<obj.m_camera_distance<<'\n';

    }
    
};
//global functions
 void printObjectDistance(const ObjectDistance& obj){
    std::cout<<"radar distance : "<<obj.GetRadarDistance()<<'\n'<<"camera distance : "<<obj.GetCameraDistance()<<'\n';

 }
 ObjectDistance* createObjectDistanceOnHeap(float radar, float camera){
    return new ObjectDistance(radar,camera);
 } 


 int main(){
    ObjectDistance* objPtr = createObjectDistanceOnHeap(35.5, 34.8);
     std::cout << "--- Initial Distances ---\n";
    printObjectDistance(*objPtr);

    
    std::cout << "\n--- Calling adjustDistancesByValue ---\n";
    objPtr->adjustDistancesByValue(*objPtr);

    std::cout << "After adjustDistancesByValue (Original Object):\n";
    printObjectDistance(*objPtr);  

    
    std::cout << "\n--- Calling adjustDistancesByReference ---\n";
    objPtr->adjustDistancesByReference(*objPtr);

    std::cout << "After adjustDistancesByReference (Original Object Updated):\n";
    printObjectDistance(*objPtr);  

   
    delete objPtr;
    objPtr = nullptr;

 }
