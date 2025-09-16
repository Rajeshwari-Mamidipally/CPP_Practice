#include<iostream>
class LaneBoundary
{
private:
    
     float m_curvature;
     int m_lane_id ;
public:
    LaneBoundary(float curvature,int lane_id)      //Constructor
    :
    m_curvature(curvature),
    m_lane_id(lane_id){}
    //Getter Functions
    float GetCurvature() const{ return m_curvature;}
    int GetLaneId() const{ return m_lane_id;}

    bool compareCurvature(const LaneBoundary& other) const{   //CompareCurvature Function
        return this->m_curvature > other.m_curvature;
    }
    void display() const{
        std::cout<<"__Lane Details__"<<'\n';
        std::cout<<"Lane ID : "<<m_lane_id<<'\n';
        std::cout<<"Curvature : "<<m_curvature<<'\n';
    }
};

//Global Functions

bool isCurvatureGreater(const LaneBoundary& lane1, const 
LaneBoundary& lane2)  {
    if(lane1.GetCurvature()>lane2.GetCurvature()){
        return true;
    }
    else{ return false;}
}
void printLaneComparison(const LaneBoundary& lane1, const 
LaneBoundary& lane2) {
    if(lane1.GetCurvature()>lane2.GetCurvature()){
        std::cout<<"lane1 : "<<lane1.GetCurvature()<<'\n';
    }
    else if(lane1.GetCurvature()<lane2.GetCurvature()){
        std::cout<<"lane2 : "<<lane2.GetCurvature()<<'\n';
    }
    else{
        std::cout<<"Both are equal"<<'\n';
    }
}
int main(){
    LaneBoundary lane1( 0.015,1);
    LaneBoundary lane2( 0.023,2);
    lane1.display();
    lane2.display();
    
    // Member Function Comparison
    std::cout << "\nMember Function Comparison Result:\n";
    if (lane1.compareCurvature(lane2)) {
        std::cout << "Lane " << lane1.GetLaneId() << " has greater curvature than Lane "
             << lane2.GetLaneId() << "." << std::endl;
    } else if (lane2.compareCurvature(lane1)) {
        std::cout << "Lane " << lane2.GetLaneId() << " has greater curvature than Lane "
             << lane1.GetLaneId() << "." << std::endl;
    } else {
        std::cout << "Both lanes have equal curvature." << std::endl;
    }
    
    // Global Function Comparison
    printLaneComparison(lane1, lane2);
}


