#pragma once
#include "../utils.h"

void selectionRecursive(int* arr, int start, int size){
    if(start>=size-1)return;
    int min=arr[start];
    for(int i=start; i<size; i++)if(arr[i]<min){
        min=arr[i];
        swap(arr, start, i);
    };
    selectionRecursive(arr, start+1, size);
};