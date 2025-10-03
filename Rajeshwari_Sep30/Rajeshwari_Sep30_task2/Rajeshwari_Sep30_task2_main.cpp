#include<iostream>
#include "Rajeshwari_Sep30_task2_QuickSort.h"
int main(){
    int size;
    std::cout<<"enter the size of array \n";
    std::cin>>size;
    int arr[size];
    std::cout<<"enter elements of array\n";
    for(int i=0;i<size;i++){
        std::cin>>arr[i];
    }
   std:: cout << "Before sorting:\n";
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    quickSort(arr, 0, size - 1);

    std::cout << "After sorting:\n";
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;

}
