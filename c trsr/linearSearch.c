#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int N, int x){
    for (int i = 0; i < N; i++){
        if (arr[i] == x){
            return i;
        }
    }
    return -1;
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

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 3]);
    }


    int result = search(arr, size, key);

    if (result != -1) {
        printf("%d\n", result + 1);
    } else if (result == -1){
        printf("not found\n");
    }

    free(arr);
    return 0;
}