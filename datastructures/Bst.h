#pragma once
#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

class Bst{
    public:
        Node* root;
        Bst():root(NULL){};
        Bst(Node* root_t):root(root_t){};
        ~Bst(){};
        bool isEmpty();
        void insert(int);
        void remove(int){};
        void print(){};
        void printInorder();
        void printPreorder();
        void printPostorder();
};


bool Bst::isEmpty(){
    return root == NULL;
};

void Bst::insert(int data){
    // cout<<data<<"\t";
    Node *newNode = new Node;
    if(this->isEmpty()){
        this->root = newNode;
        this->root->data = data;
        this->root->left = NULL;
        this->root->right = NULL;
        return;
    };
    Node* root_t=this->root;
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

void Bst::printPreorder(){
    if(!this->root)return;
    cout<<this->root->data<<"\t";
    Bst(this->root->left).printPreorder();
    Bst(this->root->right).printPreorder();
}

void Bst::printPostorder(){
    if(!this->root)return;
    Bst(this->root->left).printPreorder();
    Bst(this->root->right).printPreorder();
    cout<<this->root->data<<"\t";
}

void Bst::printInorder(){
    if(!this->root)return;
    Bst(this->root->left).printPreorder();
    cout<<this->root->data<<"\t";
    Bst(this->root->right).printPreorder();
}