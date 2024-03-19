#include <stdio.h>
#include <stdlib.h>

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


    int result = optimized(arr, size, key);

    if (result != -1) {
        printf("%d\n", result + 1);
    } else if (result == -1){
        printf("not found\n");
    }

    free(arr);
    return 0;
}