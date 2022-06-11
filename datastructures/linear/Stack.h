#pragma once

template<typename T>
class StackNode{
    public:
        T data;
        StackNode* next;
        StackNode():next(NULL){};
        ~StackNode(){};
};

template<typename T>
class Stack{
    private:
        StackNode<T>* head;
    public:
        Stack():head(NULL){};
        void push(T item);
        StackNode<T>* pop();
        long unsigned int height();
        void print();
        bool isEmpty();
        ~Stack();
};

template<typename T> void Stack<T>::push(T item){
    StackNode<T>* newNode=new StackNode<T>;
    newNode->data=item;
    newNode->next=this->head;
    this->head=newNode;
}

template<typename T> StackNode<T>* Stack<T>::pop(){
    if(!this->head) return NULL;
    StackNode<T>* temp=this->head;
    delete this->head;
    this->head=temp->next;
    return temp;
}

template<typename T> long unsigned int Stack<T>::height(){
    StackNode<T>* ptr=this->head;
    long unsigned int height=0;
    while (ptr){
        ptr=ptr->next;
        height++;
    };
    return height;
}

template<typename T> void Stack<T>::print(){
    StackNode<T>* ptr=this->head;
    while (ptr){
        cout<<"<"<<ptr->data<<">\t";
        ptr=ptr->next;
    };
    cout<<endl;
}

template<typename T> Stack<T>::~Stack(){
    StackNode<T>* ptr=this->head;
    while (ptr){
        StackNode<T>* ptrx=ptr->next;
        this->head=ptrx;
        delete ptr;
        ptr=ptrx;
    };
};

template<typename T> bool Stack<T>::isEmpty(){
    return this->head==NULL;
};
