#pragma once
#include"../utils.h"

void selectionSort(int* arr, int size){
    if(size<=1)return;
    for(int i=0; i<size; i++){
        int min=arr[i];
        for(int j=i+1; j<size; j++)if(arr[j]<min){
            min=arr[j];
            swap(arr, i, j);
        };
    };   
};