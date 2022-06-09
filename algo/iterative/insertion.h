#pragma once
#include "../utils.h"

void insertionSort(int*arr, int size){
    if(size<=1)return;
    for(int pos=1; pos<size; pos++){
        int hole=pos, temp=arr[pos];
        while(true){
            if(hole==0){
                arr[0]=temp;
                break;
            };
            if(temp<arr[hole-1]){
                swap(arr, hole, hole-1);
                hole--;
            }else{
                break;
            }
        }
    };
};