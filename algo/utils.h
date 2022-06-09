#pragma once
#include <iostream>
using namespace std;

void swap(int *arr, int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}; 

void printArray(int *arr, int size){
    cout<<"[";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<"]"<<endl;
};