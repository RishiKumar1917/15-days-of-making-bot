#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers and fill the array
void generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (size * 10); // Random numbers within the range [0, size * 10]
    }
}

// Quick Sort function
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Iterative Binary Search
int iterative_binary_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Recursive Binary Search
int recursive_binary_search(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            return recursive_binary_search(arr, low, mid - 1, target);
        }
        return recursive_binary_search(arr, mid + 1, high, target);
    }
    return -1;
}

// Function to compare time of both approaches in milliseconds
void compare_time(int arr[], int size, int target) {
    clock_t start, end;
    double time_iterative = 0.0, time_recursive = 0.0;
    const int repeat = 10000; // Number of repetitions to make the time measurable

    // Iterative Binary Search
    start = clock();
    for (int i = 0; i < repeat; i++) {
        iterative_binary_search(arr, size, target);
    }
    end = clock();
    time_iterative = ((double)(end - start)) / CLOCKS_PER_SEC * 1000 / repeat; // Convert to milliseconds

    // Recursive Binary Search
    start = clock();
    for (int i = 0; i < repeat; i++) {
        recursive_binary_search(arr, 0, size - 1, target);
    }
    end = clock();
    time_recursive = ((double)(end - start)) / CLOCKS_PER_SEC * 1000 / repeat; // Convert to milliseconds

    printf("Array Size: %d\n", size);
    printf("Iterative Binary Search Time: %f milliseconds\n", time_iterative);
    printf("Recursive Binary Search Time: %f milliseconds\n", time_recursive);
    printf("\n");
}

int main() {
    srand(time(0));

    // Array sizes
    int size1 = 10000;
    int size2 = 100000;
    int size3 = 1000000;

    // Initialize arrays
    int *arr1 = (int *)malloc(size1 * sizeof(int));
    int *arr2 = (int *)malloc(size2 * sizeof(int));
    int *arr3 = (int *)malloc(size3 * sizeof(int));

    generate_random_array(arr1, size1);
    generate_random_array(arr2, size2);
    generate_random_array(arr3, size3);

    // Sort arrays
    quick_sort(arr1, 0, size1 - 1);
    quick_sort(arr2, 0, size2 - 1);
    quick_sort(arr3, 0, size3 - 1);

    // Choose a random target from each array
    int target1 = arr1[rand() % size1];
    int target2 = arr2[rand() % size2];
    int target3 = arr3[rand() % size3];

    // Compare time for both approaches on each array
    compare_time(arr1, size1, target1);
    compare_time(arr2, size2, target2);
    compare_time(arr3, size3, target3);

    // Free allocated memory
    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}
