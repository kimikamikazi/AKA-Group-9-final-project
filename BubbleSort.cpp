#include <iostream>
#include <chrono>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int maxInputSize = 1000;
    const int stepSize = 50;

    for (int inputSize = 50; inputSize <= maxInputSize; inputSize += stepSize) {
        int arr[inputSize];

        // Initialize array with random values or any desired values

        auto start = std::chrono::high_resolution_clock::now();

        // Measure the time for bubble sort
        bubbleSort(arr, inputSize);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        std::cout << "Input Size: " << inputSize << ", Running Time: " << duration << " microseconds\n";
    }

    return 0;
};