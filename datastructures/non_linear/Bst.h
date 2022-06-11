#pragma once
#include<iostream>
#include "../linear/Queue.h"
#include "../linear/Stack.h"

using namespace std;

template<typename T>
class BstNode{
    public:
        T data;
        BstNode* right;
        BstNode* left;
        BstNode():right(NULL), left(NULL){};
        ~BstNode(){};
};

template<typename T>
class Bst{
    public:
        BstNode<T>* root;
        Bst():root(NULL){};
        Bst(BstNode<T>* root_t):root(root_t){};
        ~Bst(){};
        bool isEmpty();
        bool doesExist(T data);
        bool isSubtree(BstNode<T>* subTree);
        Queue<BstNode<T>*> getBranch(BstNode<T>* subTree);
        BstNode<T>* getRightMin();
        void insert(T);
        bool remove(T);
        void print(){};
        void printInorder();
        void printPreorder();
        void printPostorder();
        void breadthFirstSearch();
        void depthFirstSearchRecursive();
        void depthFirstSearchIterative();
        long unsigned int countNodes();
        long unsigned int getHeight();
};

template<typename T> bool Bst<T>::isEmpty(){
    return this->root == NULL;
};

template<typename T> void Bst<T>::insert(T data){
    BstNode<T> *newNode = new BstNode<T>;
    if(this->isEmpty()){
        this->root = newNode;
        this->root->data = data;
        this->root->left = NULL;
        this->root->right = NULL;
        return;
    };
    BstNode<T>* root_t=this->root;
    while(true){
        if(data<root_t->data){
            if(root_t->left){
                root_t=root_t->left;
            }else{
                root_t->left=newNode;
                root_t->left->data=data;
                root_t->left->left=NULL;
                root_t->left->right=NULL;
                return;
            };
        }else{
            if(root_t->right){
                root_t=root_t->right;
            }else{
                root_t->right=newNode;
                root_t->right->data=data;
                root_t->right->left=NULL;
                root_t->right->right=NULL;
                return;
            };
        }
    }
    
};

template<typename T> void Bst<T>::printPreorder(){
    if(!this->root)return;
    cout<<"<"<<this->root->data<<">\t";
    Bst(this->root->left).printPreorder();
    Bst(this->root->right).printPreorder();
}

template<typename T> void Bst<T>::printPostorder(){
    if(!this->root)return;
    Bst(this->root->left).printPreorder();
    Bst(this->root->right).printPreorder();
    cout<<"<"<<this->root->data<<">\t";
}

template<typename T> void Bst<T>::printInorder(){
    if(!this->root)return;
    Bst(this->root->left).printPreorder();
    cout<<"<"<<this->root->data<<">\t";
    Bst(this->root->right).printPreorder();
}

template<typename T> bool Bst<T>::doesExist(T data){
    if(!this->root)return false;
    if(this->root->data==data)return true;
    if(Bst(this->root->left).doesExist(data))return true;
    return Bst(this->root->right).doesExist(data);
}

template<typename T> bool Bst<T>::isSubtree(BstNode<T>* subTree){
    if(this->isEmpty() || subTree==NULL) return false;
    if(this->root==subTree) return true;
    if(Bst(this->root->left).isSubtree(subTree)) return true;
    return Bst(this->root->right).isSubtree(subTree);
};

template<typename T> Queue<BstNode<T>*> Bst<T>::getBranch(BstNode<T>* subTree){
    Queue<BstNode<T>*> queue=Queue<BstNode<T>*>();
    if(this->root==subTree){
        queue.enqueue(this->root);
        return queue;
    };
    if(this->root->left) queue.concat(Bst(this->root->left).getBranch(subTree));
    if(queue.isEmpty())if(this->root->right)queue.concat(Bst(this->root->right).getBranch(subTree));
    if(queue.isEmpty()) return queue;
    queue.enqueue(this->root);
    return queue;
};

template<typename T> void Bst<T>::breadthFirstSearch(){
    Queue<BstNode<T>*> queue=Queue<BstNode<T>*>();
    BstNode<T>* root_t=this->root;
    if(this->root) queue.enqueue(this->root);
    cout<<endl;
    while(!queue.isEmpty()){
        root_t=queue.dequeue()->data;
        // the processing here is just printing the data out
        cout<<"<"<<root_t->data<<">\t";
        cout<<queue.length()<<endl;
        if(root_t->left) queue.enqueue(root_t->left);
        if(root_t->right) queue.enqueue(root_t->right);

    };
    cout<<endl;
};

template<typename T> void Bst<T>::depthFirstSearchRecursive(){
    this->printInorder();
};

template<typename T> void Bst<T>::depthFirstSearchIterative(){
    Stack<BstNode<T>*> stack=Stack<BstNode<T>*>();
    if(this->isEmpty())return;
    BstNode<T>* node_t=this->root;
    stack.push(node_t);
    while(!stack.isEmpty()){
        node_t=stack.pop()->data;
        cout<<"<"<<node_t->data<<">\t";
        if(node_t->right)stack.push(node_t->right);
        if(node_t->left)stack.push(node_t->left);
    };
    cout<<endl;
};

template<typename T> long unsigned int Bst<T>::countNodes(){
    if(this->isEmpty())return 0;
    return 1 + Bst(this->root->left).countNodes() + Bst(this->root->right).countNodes();
};

template<typename T> long unsigned int Bst<T>::getHeight(){
    if(this->isEmpty())return 0;
    long unsigned int height=0;
    long unsigned int rightHeight=Bst(this->root->right).getHeight();
    long unsigned int leftHeight=Bst(this->root->left).getHeight();
    return 1 + (rightHeight>leftHeight ? rightHeight: leftHeight);
};

// this function is not completed yet;)
template<typename T> bool Bst<T>::remove(T data){
    if(this->isEmpty())return false;
    if(this->root->right && this->root->left){
        if(this->root->data==data){
            BstNode<T>* min=this->getRightMin();
            this->root->data=min->data;
            Bst(this->root->right).remove(min->data);
            return true;
        }else{
            if(Bst(this->root->right).remove(data) || Bst(this->root->left).remove(data))return true;
            return false;
        }
    };
    if(this->root->right){
        if(this->root->data==data){
            // go back later
        }else{

        }
    }
    return false;
};

template<typename T> BstNode<T>* Bst<T>::getRightMin(){
    if(this->isEmpty())return NULL;
    BstNode<T>* ptr=this->right;
    BstNode<T>* p=this->right;
    while(ptr){
        BstNode<T>* p=ptr;
        ptr=ptr->left;
    };
    return p;
};