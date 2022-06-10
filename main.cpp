#include<iostream>
#include "algo/iterative/bubble.h"
#include "algo/recursive/bubble.h"
#include "algo/iterative/selection.h"
#include "algo/recursive/mergeSort.h"
#include "algo/recursive/quickSort.h"
#include "datastructures/Bst.h"
#include "algo/utils.h"
using namespace std;


int main(){
    int N=10; 
    int arr[N]={7, 1, 0, 4, 2, 3, 9, 8, 5, 6};
    Bst bst=Bst();
    for(int i=0; i<N; i++)bst.insert(arr[i]);
    cout<<"Preorder:\t";
    bst.printPreorder();
    cout<<endl;
    cout<<"Postorder:\t";
    bst.printPostorder();
    cout<<endl;
    cout<<"Inorder:\t";
    bst.printInorder();
    return 0;
}