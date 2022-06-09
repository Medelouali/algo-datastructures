#pragma once
#include "../utils.h"

void bubbleSort(int* arr, int n){
    for(int i=0; i<n; i++){
        bool sorted=true;
        for(int j=0; j<n-1-i; j++)if(arr[j]>arr[j+1]){
            swap(arr, j, j+1);
            sorted=false;
        };
        if(sorted)break;
    };
};

