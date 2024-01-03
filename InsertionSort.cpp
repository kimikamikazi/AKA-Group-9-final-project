#include <iostream>
#include <chrono>
#include <cstdlib> // for std::rand

void recursiveInsertionSort(int arr[], int n) {
    // Base case: if the array has only one element, it is already sorted
    if (n <= 1)
        return;

    // Sort the first n-1 elements recursively
    recursiveInsertionSort(arr, n - 1);

    // Insert the last element into its correct position
    int lastElement = arr[n - 1];
    int j = n - 2;

    // Move elements greater than lastElement to the right
    while (j >= 0 && arr[j] > lastElement) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = lastElement;
}

int main() {
    const int maxInputSize = 1000;
    const int stepSize = 50;

    for (int inputSize = 50; inputSize <= maxInputSize; inputSize += stepSize) {
        int arr[inputSize];

        // Initialize array with random values
        for (int i = 0; i < inputSize; ++i) {
            arr[i] = std::rand() % 1000; // adjust range as needed
        }

        auto start = std::chrono::high_resolution_clock::now();

        // Measure the time for recursive insertion sort
        recursiveInsertionSort(arr, inputSize);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        std::cout << "Input Size: " << inputSize << ", Running Time: " << duration << " microseconds\n";
    }

    return 0;
}