#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int* xp, int* yp){
    int temp =*xp;
    *xp =  *yp;
    *yp = temp;
}

void sort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n; i++){
        swapped = false;
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; // Key found, return index
        }
        if (arr[mid] < key) {
            left = mid + 1; // Continue searching in the right half
        } else {
            right = mid - 1; // Continue searching in the left half
        }
    }
    return -1; // Key not found
}

int main(int argc, char *argv[]) {
    time_t start, end;

    if (argc < 3) {
        printf("Usage: %s <array_size> <key> <array_elements...>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);
    int key = atoi(argv[2]);

    if (argc != size + 3) {
        printf("Invalid number of array elements\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 3]);
    }

    sort(arr, size);

    time(&start);

    int result = binarySearch(arr, size, key);

    time(&end);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    double time_taken = end - start;
    printf("Time taken by program is: %.5f sec\n", time_taken);


    free(arr);

    return 0;
}
