#include<iostream>
#include "QuickSort.h"
int partitioning(int arr[], int start, int end) {
    int pivot = arr[start];  // choose first element as pivot
    int left = start + 1;
    int right = end;

    while (true) {
        while (left <= right && arr[left] <= pivot) left++;
        while (left <= right && arr[right] >= pivot) right--;

        if (left > right) break;
        else swap(arr[left], arr[right]);
    }

    swap(arr[start], arr[right]); // place pivot in final position
    return right;
}
void quickSort(int arr[],int start,int end){
    if (start < end) {
        int pivotIndex = partitioning(arr, start, end);

        quickSort(arr, start, pivotIndex - 1); // sort left subarray
        quickSort(arr, pivotIndex + 1, end);   // sort right subarray
    }
}
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}