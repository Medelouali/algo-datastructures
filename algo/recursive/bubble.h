#pragma once
#include "../utils.h" 

void bubbleRecursive(int* arr, int n){
    bool isSorted=true;
    if(n<=0)return;
    for(int i=0; i<n-1; i++)if(arr[i]>arr[i+1]){
        swap(arr, i, i+1);
        isSorted=false;
    };
    if(isSorted)return;
    bubbleRecursive(arr, n-1);
};

