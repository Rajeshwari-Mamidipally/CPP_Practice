#include<iostream>
#include<iomanip>
int main(){
    //Declare an array of type double called numbers with 10 elements, and initialize the elements to the values 0.0,1.1,2.2, …, 9.9. Assume that the symbolic constant SIZE hasbeen defined as 10.
    const int SIZE=10;
    double numbers[]={0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
   
    //Declare a pointer nPtr that points to a variable of type double.
    double *nPtr;
    //print the elements of array numbers using array subscript notation.
    std::cout<<"\nDisplaying the elements of array numbers using array subscript notation.\n";
    for(int i=0;i<SIZE;i++){
        std::cout<<"number "<<i+1<<" : "<<std::fixed << std::setprecision(1)<<numbers[i]<<'\n';
    }
    // assign the starting address of array numbers to the pointer variable nPtr.
    nPtr=numbers;
    nPtr=&numbers[0];
    // print the elements of array numbers using pointer/offset notation with pointer nPtr.
    std::cout<<"\nDisplaying the elements of array numbers using pointer/offset notation with pointer nPtr.\n";
    for(int j=0;j<SIZE;j++){
        std::cout<<"number "<<j+1<<" : "<< std::fixed << std::setprecision(1)<< *(nPtr + j)<<'\n';
    }
    // print the elements of array numbers using pointer/offset notation with the array name as the pointer.
    std::cout<<"\nDisplaying the elements of array numbers using pointer/offset notation with the array name as the pointer.\n";
    for(int j=0;j<SIZE;j++){
        std::cout<<"number "<<j+1<<" : "<< std::fixed << std::setprecision(1)<<*(numbers+j)<<'\n';
    }
    // print the elements of array numbers using pointer/subscript notation with pointer nPtr.
    std::cout<<"\nDisplaying the elements of array numbers using pointer/subscript notation with pointer nPtr.\n";
    for(int j=0;j<SIZE;j++){
        std::cout<<"number "<<j+1<<" : "<< std::fixed << std::setprecision(1)<<nPtr[j]<<'\n';
    }
    std::cout<<"\nrefering to the fourth element of array \n";
    std::cout << "subscript notation numbers[3] : " << numbers[3] << '\n';       // Array subscript
    std::cout << "pointer/offset notation with the array name as the pointer *(numbers+3): " << *(numbers + 3) << '\n'; // Pointer/offset with array name
    std::cout << "pointe subscript notation nPtr[3] : " << nPtr[3] << '\n';             // Pointer subscript
    std::cout << "pointer/offset notation *(nPtr + 3) = " << *(nPtr + 3) << '\n';     // Pointer/offset
    std::cout<<"\nrefering to nPtr+8\n";
    std::cout << "Address of nPtr + 8: " << (nPtr + 8) << '\n';
    std::cout << "Value at *(nPtr + 8): " << *(nPtr + 8) << '\n';
    nPtr = &numbers[5];
    nPtr -= 4;
    std::cout << "\nnPtr -= 4 from numbers[5] \n";
    std::cout << "Address: " << nPtr << '\n';
    std::cout << "Value: " << *nPtr << '\n';

    return 0;
}