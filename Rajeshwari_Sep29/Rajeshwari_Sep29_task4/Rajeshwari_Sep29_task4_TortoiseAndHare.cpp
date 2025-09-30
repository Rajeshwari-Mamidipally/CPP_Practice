#include<iostream>
#include "TortoiseAndHare.h"
void moveTortoise(int* pos){
    int i = rand()%10 + 1;
    if(i>=1&&i<=5){
        *pos+=3;
    }
    else if(i==6||i==7){
        *pos-=6;
    }
    else{
        *pos+=1;
    }
}
void moveHare(int* pos){
    int i=rand()%10+1;
     if(i==1 || i==2){}
    if(i==3||i==4){
        *pos+=9;
    }
    else if(i==5){
        *pos-=12;
    }
    else if(i>=6&&i<=8){
        *pos+=1;
    }
    else{
        *pos-=2;
    }
}