#include "BucketSort.h"
#include <iostream>
#include <iomanip>
using namespace std;
// Get the maximum element in the array
int BucketSort::getMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

// Extract digit at given position
// position = 1 -> ones, 10 -> tens, 100 -> hundreds, etc.
int BucketSort::getDigit(int number, int position) {
    return (number / position) % 10;
}

// Perform bucket sort
void BucketSort::bucketSort(int arr[], int size) {
    const int NUM_BUCKETS = 10;

    // 2D bucket array: 10 rows x size columns
    int buckets[NUM_BUCKETS][100]; // assuming max size <= 100
    int bucketCount[NUM_BUCKETS];  // to keep track of count in each bucket

    int maxVal = getMax(arr, size);

    // For each digit position (ones, tens, hundreds, etc.)
    for (int pos = 1; maxVal / pos > 0; pos *= 10) {

        // Reset bucket counts
        for (int i = 0; i < NUM_BUCKETS; i++)
            bucketCount[i] = 0;

        // ----- Distribution pass -----
        for (int i = 0; i < size; i++) {
            int digit = getDigit(arr[i], pos); 
            buckets[digit][bucketCount[digit]++] = arr[i];
        }

        // ----- Gathering pass -----
        int index = 0;
        for (int i = 0; i < NUM_BUCKETS; i++) {
            for (int j = 0; j < bucketCount[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }

        // Display current pass result
        cout << "After pass (position = " << pos << "): ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
