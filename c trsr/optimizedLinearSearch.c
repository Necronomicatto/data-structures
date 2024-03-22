#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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

int optimized(int arr[], int size, int key){
    int i;
    arr[size] = key;
    for (i = 0; arr[i] != key; i++);
    if (i == size) {
        return -1;
    }
    return i;
}

int main(int argc, char* argv[]){
    time_t start, end;
    if (argc < 3) {
        printf("Usage: %s <size> <key> <elements>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);
    int key = atoi (argv[2]);

    if (argc != size +3 ){
        printf("invalid number of array elements\n");
        return 1;
    }

    int *arr = (int *)malloc((size + 1) * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 3]);
    }

    sort(arr, size);

    time(&start);

    int result = optimized(arr, size, key);

    time(&end);

    if (result != -1) {
        printf("%d in the sorted array\n", result);
    } else if (result == -1){
        printf("not found\n");
    }

    double time_taken = end - start;
    printf("Time taken by program is: %.5f sec\n", time_taken);

    free(arr);
    return 0;
}