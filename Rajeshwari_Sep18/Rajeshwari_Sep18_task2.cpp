#include<iostream>
class  EgoVehicleData
{
private:
    int num_lanes;
    float* lane_positions;
    float* sensor_confidence;
public:
     EgoVehicleData(int lanes,float* positions,float* confidence)   
     :
     num_lanes(lanes)
     {
        lane_positions=new float[num_lanes];
        sensor_confidence=new float[num_lanes];
        for(int i=0;i<num_lanes;i++){
            lane_positions[i]=positions[i];
            sensor_confidence[i]=confidence[i];
        }
        
     }
    ~ EgoVehicleData(){
        delete[] lane_positions;
        delete[] sensor_confidence;
        lane_positions=nullptr;
        sensor_confidence=nullptr;
    }
    //getter functions
    int getLanes()const{return num_lanes;}
    float* getLanePositions() const{return lane_positions;}
    float* getSensorConfidence() const{return sensor_confidence;}

    float getAverageLanePosition() const{   //finding average of lane positions
        float avg=0;
        for(int i=0;i<num_lanes;i++){
            avg+=lane_positions[i];
        }
        return avg/num_lanes;
    }
    void updateSensorConfidence(float factor){ 
        for(int i=0;i<num_lanes;i++){
            sensor_confidence[i]*=factor;
        }
    }
};

//global functions
void findHighestConfidenceVehicle(EgoVehicleData* array, int size, const EgoVehicleData*& highest){
    if (size <= 0 || array == nullptr) {
        highest = nullptr; 
        return;
    }

    float maxSum = -1.0f;
    highest = nullptr;
    for (int i = 0; i < size; i++) {
        float currentSum = 0.0f;
        float* scores = array[i].getSensorConfidence();

        for (int j = 0; j < array[i].getLanes(); j++) {
            currentSum += scores[j];
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
            highest = &array[i];
        }
    }

}

void printEgoVehicleData(const EgoVehicleData& data){ //printing details of lane positions and confidence scores
    std::cout<<"\nDisplaying lane positions\n";
    for(int i=0;i<data.getLanes();i++){
        std::cout<<"position "<<i<<": "<<data.getLanePositions()[i]<<'\n';

    }
    std::cout<<"\nDisplaying confidence scores\n";
    for(int i=0;i<data.getLanes();i++){
        std::cout<<"score "<<i<<" : "<<data.getSensorConfidence()[i]<<'\n';
    }
}
void printHighestConfidenceVehicle(const EgoVehicleData* vehicle) {  
    if(vehicle!=nullptr){
        printEgoVehicleData(*vehicle);
    }
    else{
        std::cout<<"warning: no vehicle data available\n";
    }
}
int main(){
    int num_lanes=3;
    float lane_positions1[]={3.2f, 3.0f, 3.4f};
    float sensor_confidence1[]={0.95f, 0.97f, 0.93f};

    float lane_positions2[]={2.9f, 2.8f, 3.1f};
    float sensor_confidence2[]={0.92f, 0.90f, 0.88f};

    float lane_positions3[]={3.4f, 3.5f, 3.6f};
    float sensor_confidence3[]={0.99f, 0.98f, 0.97f};

    EgoVehicleData* vehicles=new EgoVehicleData[3]{
        {num_lanes,lane_positions1,sensor_confidence1},
        {num_lanes,lane_positions2,sensor_confidence2},
        {num_lanes,lane_positions3,sensor_confidence3}};
    vehicles[0].updateSensorConfidence(1.05f); 
    vehicles[1].updateSensorConfidence(1.02f); 
    vehicles[2].updateSensorConfidence(1.10f); 
     const EgoVehicleData* highestVehicle = nullptr;
    findHighestConfidenceVehicle(vehicles,3,highestVehicle);
    printHighestConfidenceVehicle(highestVehicle);
    delete[] vehicles;
    return 0;
}


