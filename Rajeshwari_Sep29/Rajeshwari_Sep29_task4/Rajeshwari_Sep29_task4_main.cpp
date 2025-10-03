#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<windows.h>
#include<string>
#include "Rajeshwari_Sep29_task4_TortoiseAndHare.h"
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int tortoise = 1, hare = 1;
    std::cout<<"BANG !!!!! \n AND THEY'RE OFF !!!!!\n";
    while(true){
        moveTortoise(&tortoise);
        moveHare(&hare);
        if(tortoise<1) tortoise=1; //if position  value is less than 1 then assigh 1 to tortoise
        if(hare<1) hare=1;//if position value is less than 1 then assign 1 to hare
        int T=std::min(tortoise,70);
        int H=std::min(hare,70);
        std::string track(70,' ');
        if(T==H){
           std::string ouch = "OUCH!!!";
           int start = T - 1; 
           for (size_t k = 0; k < ouch.size() && start + k < track.size(); ++k) {
              track[start + k] = ouch[k];
            }
        }
        else {
            track[T-1]='T';
            track[H-1]='H';

        }
        std::cout << track << std::endl;

        bool tortFinished = (tortoise >= 70);
        bool hareFinished  = (hare >= 70);

        if (tortFinished && hareFinished) { //if both are at same 
            std::cout << "It's a tie.\n";
            break;
        } else if (tortFinished) {
            std::cout << "TORTOISE WINS!!! YAY!!!\n";
            break;
        } else if (hareFinished) {
            std::cout << "Hare wins. Yuch.\n";
            break;
        }
        Sleep(1000);
    }
    
    
  return 0;
    


}
