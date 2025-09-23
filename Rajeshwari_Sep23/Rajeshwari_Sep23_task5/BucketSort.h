
class BucketSort {
public:
    // Function to perform bucket sort
    static void bucketSort(int arr[], int size);

private:
    static int getMax(int arr[], int size);      // Get maximum number to know number of digits
    static int getDigit(int number, int position); // Extract digit at given position
};

