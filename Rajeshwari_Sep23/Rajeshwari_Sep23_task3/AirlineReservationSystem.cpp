#include<iostream>
#include <algorithm>
#include "AirlineReservationSystem.h"
AirlineReservationSystem::AirlineReservationSystem()
{
    seats.fill(false); //filling seats array with false in begining

}
void AirlineReservationSystem::EnterChoice(){  
    while(true){
        if(isFull(0,NumSeats-1)){   //checking availability of seats
            std::cout<<"All seats are booked.\n";
            break;
        }
    std::cout<<"Please type 1 for 'First Class' and Please type 2 for 'Economy'"<<'\n';
    int ch;
    std::cin>>ch;
    if(ch==1){
         if (!assignSeat(0, 4, "First Class")) {  //if assignSeat function return false that means seats are not available in first class 
            std::cout << "First Class is full. Is it acceptable to be placed in the Economy section? (Yes/No): ";
                std::string response;
                std::cin >> response;
                std::transform(response.begin(), response.end(), response.begin(), ::tolower);

                if (response == "yes") {
                    if (!assignSeat(5, 9, "Economy")) {  //if assignSeat function is false means every seat is filled in economy
                        std::cout << "Economy is also full. Next flight leaves in 3 hours.\n";
                    }
                } else {
                    std::cout << "Next flight leaves in 3 hours.\n";
                }
            }
    }
    else if(ch==2){
         if (!assignSeat(5, 9, "Economy")) { //if assignSeat function returns false that means seats in economy are filled already
                std::cout << "Economy is full. Is it acceptable to be placed in the First Class section? (Yes/No): ";
                std::string response;
                std::cin >> response;
                std::transform(response.begin(), response.end(), response.begin(), ::tolower);

                if (response == "yes") {
                    if (!assignSeat(0, 4, "First Class")) {
                        std::cout << "First Class is also full. Next flight leaves in 3 hours.\n";
                    }
                } else {
                    std::cout << "Next flight leaves in 3 hours.\n";
                }
            }
    }
     else {
            std::cout << "Invalid choice. Please try again.\n";
        }
  }
}

bool AirlineReservationSystem::isFull(int start, int end) {  //checking whether seats are full
    for (int i = start; i <= end; i++) {
        if (!seats[i]) return false; //if seat at index i is not booked return false
    }
    return true;  //if all seats are booked then return true
}

bool AirlineReservationSystem::assignSeat(int start, int end, const std::string& sectionName) {  ///assigning seat and displaying seat number and section(first class or economy)
    for (int i = start; i <= end; ++i) {
        if (!seats[i]) { // if seats array of index i false then seats will assign
            seats[i] = true;
            std::cout << "\nBoarding Pass:\n";
            std::cout << "Seat Number: " << (i + 1) << "\n";
            std::cout << sectionName << " Section\n";
            return true;
        }
    }
    return false; // No available seat
}