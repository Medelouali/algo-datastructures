#pragma once
#include "../utils.h"

void quickSort(int* arr, int start, int end){
    if(start>=end)return;
    int pivot=arr[start], left=start, right=end;
    while(right>=left){
        while(arr[left]<=pivot)left++;
        while(arr[right]>pivot)right--;
        if(right>=left)swap(arr, left, right);
    };
    swap(arr, start, right);
    quickSort(arr, start, right-1);
    quickSort(arr, right+1, end);

}