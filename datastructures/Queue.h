#pragma once

template<typename T>
class QueueNode{
    public:
        T data;
        QueueNode* next;
        QueueNode():next(NULL){};
        ~QueueNode();
};

template<typename T>
class Queue{
    public:
        QueueNode<T>* head;
        QueueNode<T>* tail;

        Queue():head(NULL), tail(NULL){};
        void enqueue(T item){
            QueueNode<T>* newNode=new QueueNode<T>;
            if(!this->tail){
                head=tail=newNode;
                return;
            };
            this->tail->next=newNode;
            this->tail=newNode;
        };
        QueueNode<T>* dequeue(){
            if(!this->head)return NULL;
            QueueNode<T>* ptr=this->head;
            this->head=this->head->next;
            delete ptr;
            return ptr;
        };
        // we'll overload the << operator
        void printQueue(){
            QueueNode<T>* ptr=this->head;
            while(ptr){
                cout<<ptr->data<<"\t";
                ptr=ptr->next;
            };
        };
        // ~Queue(){
        //     while(this->head){
        //         QueueNode<T>* ptr=this->head->next;
        //         delete this->head;
        //         this->head=ptr;
        //     }
        // };
};


