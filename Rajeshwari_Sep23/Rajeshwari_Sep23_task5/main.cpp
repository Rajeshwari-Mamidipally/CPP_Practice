#include <iostream>
#include "BucketSort.h"
int main() {
    int size;
    std::cout<<"Enter the array size : ";
    std::cin>>size;
    int arr[size];
    std::cout<<"\nEnter the elements into array : ";
    for(int i=0;i<size;i++){
        std::cout<<"Enter element "<<i<<" " ;
        std::cin>>arr[i];
    }
    std::cout << "Original array: "; //displaying original array elements
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout <<std::endl;

    BucketSort::bucketSort(arr, size); //calling bucketsort function to sort elements in array

    std::cout << "\nSorted array: "; //displaying array elements after sorting
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout <<std::endl;

    return 0;
}

