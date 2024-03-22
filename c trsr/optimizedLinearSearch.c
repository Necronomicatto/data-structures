#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void gen_random_numbers(int *arr, int size, int min, int max){
    for (int i =0; i < size; i++){
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 
   
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
 
    i = 0; 

    j = 0; 
  
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
   
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
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
    clock_t start, end;
    int sizeN = 1000000;
    int sizeQ = 1000;

    int key[sizeQ];
    int arr[sizeN];
    int arr2[sizeQ];

    gen_random_numbers(arr, sizeN, 0, 100000);
    gen_random_numbers(key, sizeQ, 0, 100000);

    start = clock();

    mergeSort(arr, 0,  sizeN - 1);
    for (int i = 0; i < sizeQ; i++){
        int result = optimized(arr, sizeN, key[i]);
        arr2[i] = result;
    }
    end = clock();

    printf("\nTime taken by program is: %.10f sec\n", (((double) end - start) / CLOCKS_PER_SEC));

    return 0;
}