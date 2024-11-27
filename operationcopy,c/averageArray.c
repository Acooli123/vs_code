#include <stdio.h>
#include <math.h>

double calculate_average(int arr[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total / size;
}

double calculate_standard_deviation(int arr[], int size) {
    double avg = calculate_average(arr, size);
    double variance = 0;
    for (int i = 0; i < size; i++) {
        variance += pow(arr[i] - avg, 2);
    }
    variance /= size;
    return sqrt(variance);
}

int main() {
    // Example array
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Calculate average
    double avg = calculate_average(arr, size);
    printf("Average: %lf\n", avg);
    
    // Calculate standard deviation
    double std_dev = calculate_standard_deviation(arr, size);
    printf("Standard Deviation: %lf\n", std_dev);
    
    return 0;
}
