#include<iostream>
#include<cstdint>
class DetectedObject
{
private:
    uint32_t m_object_id;
    float m_rel_speed;
    float m_distance;
public:
    DetectedObject(uint32_t object_id,float rel_speed,float distance)
    :
    m_object_id(object_id),
    m_rel_speed(rel_speed),
    m_distance(distance){}
    ~DetectedObject(){}

    uint32_t getObjectId() const{return m_object_id;}
    float getRelSpeed() const{return m_rel_speed;}
    float getDistance() const{return m_distance;}

    void display() const{
        std::cout<<"ObjectId : "<<m_object_id<<'\n';
        std::cout<<"Relative Speed : "<<m_rel_speed<<'\n';
        std::cout<<"Distance : "<<m_distance<<'\n';
    }
    bool isHigherRisk(const DetectedObject& other) const{
        if (this->m_distance < other.getDistance() && this->m_rel_speed > other.getRelSpeed()) {
            return true;
         }
        return false;
    }

    void updateValuesByValue(DetectedObject obj){
        obj.m_rel_speed += 2;
        obj.m_distance -= 5;
    }
    void updateValuesByReference(DetectedObject& obj){
        obj.m_rel_speed+=2;
        obj.m_distance-=5;
    }

    
};

 void findHighestRiskObject(DetectedObject* arr, uint32_t size, const DetectedObject*& riskObj){
    if (arr == nullptr || size == 0) {
        riskObj = nullptr;  
        return;
    }

    riskObj = &arr[0];  

    for (uint32_t i = 1; i < size; ++i) {
        if (arr[i].isHigherRisk(*riskObj)) {
            riskObj = &arr[i];  
        }
    }
 }
 void printDetectedObject(const DetectedObject& obj) {
    std::cout<<"\n===Printing object details===\n"<<"ObjectId : "<<obj.getObjectId()<<"\n"<<"Relative Speed : "<<obj.getRelSpeed()<<"\n"<<"Distance : "<<obj.getDistance()<<'\n';
 }
void printHighestRiskObject(const DetectedObject* obj){
    if(obj != nullptr){
        std::cout<<"\nHighest Risk Object Details\n";
        obj->display();
    }
    else{
        std::cout<<"Warning"<<'\n';
    }

}
void updateObjectValuesByValueGlobal(DetectedObject obj) {
    obj.updateValuesByValue(obj);
}
void updateObjectValuesByReferenceGlobal(DetectedObject& obj){
    obj.updateValuesByReference(obj);
}


int main(){
     uint32_t size = 3;
    DetectedObject* object=new DetectedObject[3]{
        {701,15,55},
        {702,20,35},
        {703,10,30}
    };
    std::cout << "\nInitial Detected Objects:\n";
    for (uint32_t i = 0; i < size; ++i) {
        printDetectedObject(object[i]);
    }
    std::cout << "\nUpdating first object BY VALUE (should NOT affect original):\n";
    updateObjectValuesByValueGlobal(*object);
    printDetectedObject(*object);
    std::cout << "\nUpdating first object BY REFERENCE (original WILL change):\n";
    updateObjectValuesByReferenceGlobal(*object);
    printDetectedObject(*object); 
   const DetectedObject* highestRisk = nullptr;
   findHighestRiskObject(object, size, highestRisk);
    printHighestRiskObject(highestRisk);
    delete[] object;
    return 0;
}