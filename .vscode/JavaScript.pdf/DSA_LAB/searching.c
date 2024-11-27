#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int n, int target, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int target, int *comparisons) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int interpolationSearch(int arr[], int n, int target, int *comparisons) {
    int left = 0, right = n - 1;
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        (*comparisons)++;
        if (left == right) {
            if (arr[left] == target) {
                return left;
            }
            return -1;
        }
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));
        (*comparisons)++;
        if (arr[pos] == target) {
            return pos;
        }
        if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1;
}

void readDataFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

int main() {
    int n = MAX; // Number of elements
    int arr[n];
    int target;
    int comparisons;

    readDataFile(arr, n, "data.txt");
    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the target value to search: ");
    scanf("%d", &target);

    comparisons = 0;
    int linearResult = linearSearch(arr, n, target, &comparisons);
    printf("Linear Search: Found at index %d, Comparisons made: %d\n", linearResult, comparisons);

    comparisons = 0;
    int binaryResult = binarySearch(arr, n, target, &comparisons);
    printf("Binary Search: Found at index %d, Comparisons made: %d\n", binaryResult, comparisons);

    comparisons = 0;
    int interpolationResult = interpolationSearch(arr, n, target, &comparisons);
    printf("Interpolation Search: Found at index %d, Comparisons made: %d\n", interpolationResult, comparisons);

    return 0;
}
