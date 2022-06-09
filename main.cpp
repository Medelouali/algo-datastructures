#include<iostream>
#include "algo/iterative/bubble.h"
#include "algo/recursive/bubble.h"
#include "algo/iterative/selection.h"
#include "algo/recursive/mergeSort.h"
#include "algo/recursive/quickSort.h"
#include "algo/utils.h"
using namespace std;


int main(){
    int N=10; 
    int arr[N]={7, 1, 0, 4, 2, 3, 9, 8, 5, 6};
    printArray(arr, N);
    // bubbleSort(arr, N);
    // selectionSort(arr, 0, N);
    // insertionSort(arr, N);
    // mergeSort(arr, 0, N-1);
    // bubbleRecursive(arr, N);
    // selectionSort(arr, N);
    quickSort(arr, 0, N-1);
    printArray(arr, N);
    return 0;
}