#include<iostream>
int main(){
    const int SIZE=5;
    unsigned int values[]={2,4,6,8,10}; 
    unsigned int *vPtr;
    //Displayining  the elements of array values using array subscript notation. 
    std::cout<<"Displaying  the elements of array values using array subscript notation. \n";
    for(int i=0;i<SIZE;i++){
        std::cout<<values[i]<<"\t";
    }
    // assign the starting address of array values to pointer variable vPtr.
    vPtr=values;
    vPtr=&values[0];
    // print the elements of array values using pointer/offset notation
    std::cout<<"\nDisplaying the elements of array using pointer/offset notation \n";
    for(int i=0;i<SIZE;i++){
        std::cout<<*(vPtr+i)<<"\t";
    }
    // print the elements of array values using pointer/offset notation with the array name as the pointer.
    std::cout<<"\nDisplaying the elements of array values using pointer/offset notation with the array name as the pointer\n";
    for(int i=0;i<SIZE;i++){
        std::cout<<*(values+i)<<"\t";
    }
    // print the elements of array values by subscripting the pointer to the array.
    std::cout<<"\nDisplaying the elements of array values by subscripting the pointer to the array\n";
    for(int i=0;i<SIZE;i++){
        std::cout<<vPtr[i]<<"\t";
    }
    //Refer to the fifth element of values using array subscript notation, pointer/offset notation  with the array name as the pointer, pointer subscript notation and pointer/offset notation.
    std::cout<<"\nRefering to the fifth element\n";
    std::cout<<"using array subscript notation vPtr[4]: "<<values[4]<<'\n';
    std::cout<<"using pointer/offset notation  with array name *(values+4) : "<<*(values+4)<<'\n';
    std::cout<<"using pointer subscript vPtr[4] : "<<vPtr[4]<<'\n';
    std::cout<<"using pointer/offset notation : "<<*(vPtr+4)<<'\n';
    //address is referenced by vPtr + 3 and value at this location
    std::cout<<"address of (vPtr+3) : "<<(vPtr+3)<<'\n';
    std::cout<<"value at *(vPtr+3) : "<<*(vPtr+3)<<'\n';
    vPtr=&values[4];
    vPtr-=4;
    std::cout<<"Address : "<<vPtr<<'\n';
    std::cout<<"Value : "<<*vPtr<<'\n';

}