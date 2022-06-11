#include<iostream>
#include "algo/iterative/bubble.h"
#include "algo/recursive/bubble.h"
#include "algo/iterative/selection.h"
#include "algo/recursive/mergeSort.h"
#include "algo/recursive/quickSort.h"
#include "datastructures/non_linear/Bst.h"
#include "datastructures/linear/Queue.h"
#include "datastructures/linear/Stack.h"
#include "algo/utils.h"
using namespace std;


int main(){
    int N=10; 
    int arr[N]={7, 1, 0, 4, 2, 3, 9, 8, 5, 6};
    Bst<int> bst=Bst<int>();
    for(int i=0; i<N; i++)bst.insert(arr[i]);
    cout<<bst.getHeight();
    return 0;
}