#include <stdio.h> 
#include <stdlib.h>

int pivotReturner(int * arr, int low, int high)
{
    int i = low - 1 ; 
    for(int j = low ; j < high ; j++) {
        if(arr[j] < arr[high]) {
            i++ ; 
            int temp = arr[i] ; 
            arr[i] = arr[j] ; 
            arr[j] = temp ; 
        }
    }
    i++ ; 
    int temp = arr[i] ; 
    arr[i ] = arr[high] ; 
    arr[high] = temp ; 
    return i  ; 
}

void quickSort(int *arr, int low, int high) 
{
    if (low < high) 
    {
        int pivot = pivotReturner(arr, low, high); 
        quickSort(arr, low, pivot - 1); 
        quickSort(arr, pivot + 1, high); 
    } 
}

void arrayPrinter (int * arr , int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("%d ") ; 
    }
}

int main () {
    int size ; 
    printf("Enter the size of the array: ") ; 
    scanf("%d" , &size) ; 
    int * arr =  malloc (size * sizeof(int)) ; 
    for (int i = 0 ; i < size ; i++) {
        scanf("%d" , &arr[i]) ; 
    }
    quickSort(arr , 0 , size - 1) ; 
    arrayPrinter(arr , size) ; 
    free(arr) ; 
    arr = NULL ; 
    return 0 ; 
}