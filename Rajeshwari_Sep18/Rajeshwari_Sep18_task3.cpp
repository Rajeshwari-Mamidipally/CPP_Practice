#include<iostream>
enum SatelliteStatus{
    OPERATIONAL, 
    MAINTENANCE, 
    DECOMMISSIONED
 };
 const char* statusToString(SatelliteStatus s){
    switch(s){
        case OPERATIONAL: return "OPERATIONAL";
        case MAINTENANCE: return "MAINTENANCE";
        case DECOMMISSIONED: return "DECOMMISSIONED";

    }
 }

class SatelliteData
{
private:
    int satellite_id; 
    int num_antennas ;
    float* signal_strength;
    float orbital_altitude;
    SatelliteStatus status ;
    static int active_satellites;
public:
    SatelliteData(int id,int no_antennas,float* strength,float altitude,SatelliteStatus s)
    :
    satellite_id(id),
    num_antennas(no_antennas),
    orbital_altitude(altitude),
    status(s)
    {
        signal_strength = new float[num_antennas];
        for(int i=0;i<num_antennas;i++){
            signal_strength[i]=strength[i];

        }
        active_satellites++;

    }
    SatelliteData(const SatelliteData& other)
        : satellite_id(other.satellite_id), num_antennas(other.num_antennas),
          orbital_altitude(other.orbital_altitude), status(other.status) 
    {
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++) {
            signal_strength[i] = other.signal_strength[i];
        }
        active_satellites++;
    }
    ~SatelliteData(){
        active_satellites--;
        delete[] signal_strength;
        signal_strength=nullptr;
    }
    //getters
    int getSatelliteId()const{return satellite_id;}
    int getNumAntennas()const{return num_antennas;}
    float getAltitude()const{return orbital_altitude;}
    float* getSignalStrengths()const{return signal_strength;}
    static int getActiveSatellites(){return active_satellites;}

    float getAverageSignalStrength() const{ //finding average of signal strengths
        float avg=0;
        for(int i=0;i<num_antennas;i++){
            avg+=signal_strength[i];
        }
        return avg/num_antennas;
    }
    void boostSignal(float factor){
        for(int i=0;i<num_antennas;i++){
            signal_strength[i]*=factor;
        }
    }
    void boostSignal(float factor, float threshold) {
        for(int i=0;i<num_antennas;i++){
            if(signal_strength[i]<threshold){
                signal_strength[i]*=factor;
            }
        }
    }
    static int getActiveSatelliteCount(){
        return getActiveSatellites();
    } 
    SatelliteStatus setStatus(SatelliteStatus new_status){        //updating status wih new status
        status=new_status;
    }
    std::string getStatusString() const{
        return statusToString(status);
    }
};
int SatelliteData::active_satellites = 0;

void printSatelliteData(const SatelliteData& sd){            //Displaying the details of satellite
    
    std::cout<<"SatellieId : "<<sd.getSatelliteId()<<"\n";
    std::cout<<"Altitude : "<<sd.getAltitude()<<"\n";
    std::cout<<"Signal Strength : ";
    for (int i = 0; i < sd.getNumAntennas(); i++) {
        std::cout << sd.getSignalStrengths()[i] << " ";
    }
    
    std::cout<<"\nstatus : "<<sd.getStatusString()<<'\n';
}

bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2){ //comparing altitude of satellites
    return s1.getAltitude()>s2.getAltitude();
}
void cloneSatellite(const SatelliteData& source, SatelliteData*& target){ //clone satellite
    target = new SatelliteData(source);

}
void printActiveSatelliteCount() {
    std::cout<<"\nActive satellites : "<<SatelliteData::getActiveSatelliteCount()<<'\n'; //printing count of active satellites
}
void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold) {
    if(sd.getAverageSignalStrength()<confidence_threshold){
        sd.setStatus(MAINTENANCE);
    }
}
int main(){

    float signals1[] = {78.5f, 80.2f, 79.0f};
    float signals2[] = {75.0f, 76.5f};

    SatelliteData sat1(101, 3, signals1, 550.0f, OPERATIONAL);
    SatelliteData sat2(102, 2, signals2, 600.0f, MAINTENANCE);

    sat1.boostSignal(1.05f);          
    sat2.boostSignal(1.10f, 76.0f); 
    std::cout << "\nAltitude Comparison: \n";
    if (compareAltitude(sat1, sat2)) {
        std::cout << "Satellite 1 is higher.\n";
    } else {
        std::cout << "Satellite 2 is higher.\n";
    }
    SatelliteData* sat3 = nullptr;
    cloneSatellite(sat1, sat3);
    updateStatusIfWeak(sat1, 80.0f);
    updateStatusIfWeak(sat2, 80.0f);
    std::cout<<"\nDisplaying Satellite1 Data\n";
    printSatelliteData(sat1);
    std::cout<<"\nDisplaying Satellite2 Data\n";
    printSatelliteData(sat2);
    std::cout<<"\nDisplaying Satellite3 Data\n";
    printSatelliteData(*sat3);
    printActiveSatelliteCount();
    delete sat3;

    return 0;
}