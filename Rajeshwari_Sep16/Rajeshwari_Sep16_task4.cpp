#include<iostream>
class RadarSignal
{
private:
    int m_num_channels;
    float* m_signal_strength; 
public:
    RadarSignal(int num_channels,float* signal_strength)
    :
    m_num_channels(num_channels)
    {
        m_signal_strength=new float[m_num_channels];
        for(int i=0;i<m_num_channels;i++){
            m_signal_strength[i]=signal_strength[i];
        }

    }
    RadarSignal(const RadarSignal& other)
        : m_num_channels(other.m_num_channels)
    {
        m_signal_strength = new float[m_num_channels];
        for (int i = 0; i < m_num_channels; i++) {
            m_signal_strength[i] = other.m_signal_strength[i];
        }
    }
    ~RadarSignal(){
         delete[] m_signal_strength;
    }

    //Getter functions
    int GetNumChannels() const{return m_num_channels;}
    const float* GetSignalStrength()const{return m_signal_strength;}

    float averageSignal() const {
        float sum=0;
        for(int i=0;i<m_num_channels;i++){
            sum+=m_signal_strength[i];
        }
        float average=sum/m_num_channels;
        return average;
    }
    void boostSignalByValue(RadarSignal obj){
        std::cout<<"\nBoosting signal By value\n";
        for(int i=0;i<obj.m_num_channels;i++){
            obj.m_signal_strength[i]+=5.0;
            std::cout<<"signal strength "<<i<<" : "<<obj.m_signal_strength[i]<<'\n';        
        }
    }
    void boostSignalByReference(RadarSignal& obj){
        std::cout<<"\nBoosting signal By Reference\n";
        for(int i=0;i<obj.m_num_channels;i++){
            obj.m_signal_strength[i]+=5.0;
            std::cout<<"signal strength "<<i<<" : "<<obj.m_signal_strength[i]<<'\n';
        }
    }
};
//Global functions
void printRadarSignal(const RadarSignal& radar){
    for(int j=0;j<radar.GetNumChannels();j++){
        std::cout<<"signal strength "<<j<<" = "<<radar.GetSignalStrength()[j]<<'\n';

    }
}
 RadarSignal* createRadarSignalHeap(int num, float* signals){
    return new RadarSignal(num,signals);
 }

 int main(){
    float signals[]={55.5f, 48.2f, 60.1f, 52.6f};
    RadarSignal* obj=createRadarSignalHeap(4,signals);
    std::cout << "\n--- Initial Signal Data ---\n";
    printRadarSignal(*obj);
    std::cout << "\nAverage Signal Strength: " << obj->averageSignal() << '\n';
    obj->boostSignalByValue(*obj);
    std::cout << "\n--- After Boost by Value (Original Signals) ---\n";
    printRadarSignal(*obj);
    obj->boostSignalByReference(*obj);
    std::cout << "\n--- After Boost by Reference (Updated Signals) ---\n";
    printRadarSignal(*obj);
    delete obj;

 }

