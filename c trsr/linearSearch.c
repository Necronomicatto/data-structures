#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen_random_numbers(int *arr, int size, int min, int max){
    for (int i = 0; i < size; i++){
        arr[i] = rand() % (max - min + 1) + min;
    }
}

int search(int arr[], int N, int x){
    for (int i = 0; i < N; i++){
        if (arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]){

    clock_t start, end;   

    int sizeN = 1000000;
    int sizeQ = 100000;

    // Allocate memory dynamically using malloc
    int *key = (int*)malloc(sizeQ * sizeof(int));
    int *arr = (int*)malloc(sizeN * sizeof(int));
    int *arr2 = (int*)malloc(sizeQ * sizeof(int));

    if (key == NULL || arr == NULL || arr2 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    gen_random_numbers(arr, sizeN, 0, 100000);
    gen_random_numbers(key, sizeQ, 0, 100000);

    start = clock();
    for (int i = 0; i < sizeQ; i++){
        int result = search(arr, sizeN, key[i]);
        arr2[i] = result;
    }
    end = clock();
    
    printf("\nTime taken by program is: %.10f sec\n", (((double) end - start) / CLOCKS_PER_SEC));

    // Free allocated memory
    free(key);
    free(arr);
    free(arr2);

    return 0;
}