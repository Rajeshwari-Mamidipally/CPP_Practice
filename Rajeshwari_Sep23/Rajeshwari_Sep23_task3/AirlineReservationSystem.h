#include<string>
#include<array>
class AirlineReservationSystem{
    public:
    AirlineReservationSystem();//constructor
    void EnterChoice();
    bool assignSeat(int start, int end, const std::string& sectionName);//assign seats
    bool isFull(int start, int end);//checking seats are filled
    private:
    static const int NumSeats=10;//defining no.of.seats
    std::array<bool,NumSeats> seats; //string array defining 
    

};