#include<iostream>
class CameraConfig 
{
private:
    /* data */
     int m_num_modes;
     int* m_resolution_width;
     int* m_resolution_height;
public:
    CameraConfig (int num_modes,int* resolution_width,int* resolution_height)
    :
    m_num_modes(num_modes)
    {
        m_resolution_width = new int[m_num_modes];
        m_resolution_height = new int[m_num_modes];

        for (int i = 0; i < m_num_modes; ++i) {
            m_resolution_width[i] = resolution_width[i];
            m_resolution_height[i] = resolution_height[i];
        }
    }
     CameraConfig(const CameraConfig& other)
        : m_num_modes(other.m_num_modes) 
    {
        m_resolution_width = new int[m_num_modes];
        m_resolution_height = new int[m_num_modes];

        for (int i = 0; i < m_num_modes; ++i) {
            m_resolution_width[i] = other.m_resolution_width[i];
            m_resolution_height[i] = other.m_resolution_height[i];
        }
    }

    ~CameraConfig (){
        delete[] m_resolution_width;
        delete[] m_resolution_height;
    }
    int GetNumModes() const{return m_num_modes;}
    int* GetResolutionWidth() const{return m_resolution_width;}
    int* GetResolutionHeight() const{return m_resolution_height;}

    void printConfig() const {
        std::cout<<"==Display Cofiguration=="<<'\n';
        for(int i=0;i<m_num_modes;i++){
            std::cout<<"mode "<<i<<": "<<"\nWidth : "<<m_resolution_width[i]<<"\nHeight : "<<m_resolution_height[i]<<'\n';
        }

    }
    bool isHigherResolution(int mode1, int mode2) const {
        int resolution1=this->m_resolution_width[mode1]*this->m_resolution_height[mode1];
        int resolution2=this->m_resolution_width[mode2]*this->m_resolution_height[mode2];
        return resolution1 > resolution2;
    }
};

//Global functions

void printCameraConfig(const CameraConfig& config){
    std::cout<<"==Displaying all mode resolutions==\n";
    for(int i=0;i<config.GetNumModes();i++){
        std::cout<<"mode "<<i<<"\nWidth : "<<config.GetResolutionWidth()[i]<<"\nHeight : "<<config.GetResolutionHeight()[i]<<'\n';
    }

}
 bool globalCompareResolution(const CameraConfig& config, int m1,int m2){
    return config.isHigherResolution(m1, m2);
 } 

int main() {
    int num_modes = 3;
    int widths[] = {1920, 1280, 3840};  
    int heights[] = {1080, 2160};

    CameraConfig* cameraConfig =new CameraConfig(num_modes, widths, heights);

    std::cout << "Printing Camera Configuration (Member Function):\n";
    cameraConfig->printConfig();
    

    std::cout << "Printing Camera Configuration (Global Function):\n";
    printCameraConfig(*cameraConfig);

   
    std::cout << "\n--- Comparing Using Member Function ---\n";
    if (cameraConfig->isHigherResolution(0, 2)) {
        std::cout << "Mode 0 has a higher resolution than Mode 2.\n";
    } else {
        std::cout << "Mode 2 has a higher resolution than Mode 0.\n";
    }

   
    std::cout << "\n--- Comparing Using Global Function ---\n";
    if (globalCompareResolution(*cameraConfig, 0, 2)) {
        std::cout << "Mode 0 has a higher resolution than Mode 2.\n";
    } else {
        std::cout << "Mode 2 has a higher resolution than Mode 0.\n";
    }

    delete cameraConfig;

   
}
