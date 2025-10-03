#ifndef RAJESHWARI_OCT1_TASK1_HYBRIDVEHICLE_H
#define RAJESHWARI_OCT1_TASK1_HYBRIDVEHICLE_H
#include<string>
class HybridVehicle {
    public:
    HybridVehicle(std::string,float,float,float);
    HybridVehicle(const HybridVehicle& other); 
    ~HybridVehicle();
    HybridVehicle operator+(const HybridVehicle &r)const;
    bool operator==(const HybridVehicle &r)const;
    HybridVehicle& operator=(const HybridVehicle &r);
    HybridVehicle& operator++();
    int& operator[](int i);
    float operator()()const;
    operator float() const;  
    friend std::ostream& operator<<(std::ostream &out, const HybridVehicle &r);
    
    private:
    std::string modelName;
    float electricKm;
    float gasolineKm;
    float gasolineUsed;
    int* trips ;
    int tripCount;
    


};
#endif