#pragma once

template<typename T>
class QueueNode{
    public:
        T data;
        QueueNode* next;
        QueueNode():next(NULL){};
        ~QueueNode(){};
};

template<typename T>
class Queue{
    public:
        QueueNode<T>* head;
        QueueNode<T>* tail;

        Queue():head(NULL), tail(NULL){};
        void enqueue(T item);
        QueueNode<T>* dequeue();
        Queue<QueueNode<T>*> concat(Queue<QueueNode<T>*> queue);
        long unsigned int length();
        void print();
        bool isEmpty();
        ~Queue();
};

template<typename T> void Queue<T>::enqueue(T item){
    QueueNode<T>* newNode=new QueueNode<T>;
    newNode->data=item;
    if(!this->tail){
        head=tail=newNode;
        return;
    };
    this->tail->next=newNode;
    this->tail=newNode;
};

template<typename T> QueueNode<T>* Queue<T>::dequeue(){
    if(!this->head) return NULL;
    QueueNode<T>* ptr=this->head->next;
    QueueNode<T>* ptrx=this->head;
    delete this->head;
    this->head=ptr;
    return ptrx;
};

template<typename T> Queue<QueueNode<T>*> Queue<T>::concat(Queue<QueueNode<T>*> queue){
    Queue<QueueNode<T>*> queue_t=Queue();
    QueueNode<T>* ptr=this->head;
    while(ptr){ queue_t.enqueue(ptr); ptr=ptr->next;};
    ptr=queue->head;
    while(ptr){ queue_t.enqueue(ptr); ptr=ptr->next ;};
    return queue_t;
};

template<typename T> void Queue<T>::print(){
    QueueNode<T>* ptr=this->head;
    while(ptr){
        cout<<"<"<<ptr->data<<">\t";
        ptr=ptr->next;
    };
    cout<<endl;
};

template<typename T> Queue<T>::~Queue(){
    QueueNode<T>* ptr=this->head;
    while (ptr){
        QueueNode<T>* ptrx=ptr->next;
        this->head=ptrx;
        delete ptr;
        ptr=ptrx;
    };
}
template<typename T> long unsigned int Queue<T>::length(){
    QueueNode<T>* ptr=this->head;
    long unsigned int len=0;
    while(ptr){
        len++;
        ptr=ptr->next;
    };
    return len;
};

template<typename T> bool Queue<T>::isEmpty(){
    return this->head==NULL;
}