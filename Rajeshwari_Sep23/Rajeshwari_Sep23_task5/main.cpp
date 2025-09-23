#include <iostream>
#include "BucketSort.h"
using namespace std;

int main() {
    int arr[] = {97, 3, 100, 45, 25, 75, 150, 8, 32, 220}; //defining and initializing array
    int size = sizeof(arr) / sizeof(arr[0]); //size of array

    cout << "Original array: "; //displaying original array elements
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl << endl;

    BucketSort::bucketSort(arr, size); //calling bucketsort function to sort elements in array

    cout << "\nSorted array: "; //displaying array elements after sorting
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
