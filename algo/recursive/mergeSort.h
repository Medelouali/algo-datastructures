#pragma once

void merge(int* arr, int start, int end){
    int arr_t[end-start+1];
    int midpoint=(start+end)/2, i=start, j=midpoint+1, index=0;
    while(i<=midpoint && j<=end) arr_t[index++]=(arr[i]<=arr[j] ? arr[i++]: arr[j++]);
    while(i<=midpoint) arr_t[index++]=arr[i++];
    while(j<=end) arr_t[index++]=arr[j++];
    for(int s=0; s<index; s++)arr[start+s]=arr_t[s];
};

void mergeSort(int* arr, int start, int end){
    if(start>=end)return;
    int midpoint=(start+end)/2;
    mergeSort(arr, start, midpoint);
    mergeSort(arr, midpoint+1, end);
    merge(arr, start, end);
};
