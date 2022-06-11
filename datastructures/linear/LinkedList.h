#pragma once

template<typename T>
class ListNode{
    public:
        T data;
        ListNode* next;
        ListNode():next(NULL){};
        ~ListNode(){};
};

template<typename T>
class LinkedList{
    public:
        ListNode<T>* head;
        ListNode<T>* tail;

        LinkedList():head(NULL), tail(NULL){};
        bool addAt(T item, int index=0);
        bool removeAt(int index=0);
        ListNode<T>* getAt(int index);
        long unsigned int length();
        void print();
        ~LinkedList();
};

template<typename T> bool LinkedList<T>::addAt(T item, int index=0){
    long unsigned int len=this->length();
    if(index<0 || index>=len)return false;
    ListNode<T>* newNode=new ListNode<T>;
    newNode->data=item;
    if(index==0){
        newNode->next=this->head;
        this->head=newNode;
        if(!len)this->tail=this->head;
        return true;
    }
    if(index==len-1){
        this->tail->next=newNode;
        this->tail=newNode;
        return true;
    }
    long unsigned int position=0;
    ListNode<T>* ptr=this->head;
    while(ptr){
        if(position+1==index){
            newNode->next=ptr->next;
            ptr->next=newNode;
            return true;
        };
        position++;
        ptr=ptr->next;
    };
    return false;
};


template<typename T> bool LinkedList<T>::removeAt(int index=0){
    long unsigned int len=this->length();
    if(index<0 || index>=len)return false;
    if(!len)return false;
    if(index==0){
        ListNode<T>* ptr=this->head->next;
        delete this->head;
        this->head=ptr;
        return true;
    }
    if(index==len-1){
        ListNode<T>* ptr=this->head;
        while(ptr){
            if(!ptr->next->next){
                this->tail=ptr;
                this->tail->next=NULL;
                delete ptr->next;
            }else{
                ptr=ptr->next;
            }
        };
        return false;
    };
    long unsigned int position=0;
    ListNode<T>* ptr=this->head;
    while(ptr){
        if(position+1==index){
            ListNode<T>* temp=ptr->next;
            ptr->next=ptr->next->next;
            delete temp;
            return true;
        };
        position++;
        ptr=ptr->next;
    };
    return false;
};

template<typename T> ListNode<T>* LinkedList<T>::getAt(int index){
    long unsigned int len=this->length();
    if(index<0 || index>=len)return NULL;
    long unsigned int position=0;
    ListNode<T>* ptr=this->head;
    while(ptr){
        if(position==index)return ptr;
        position++;
        ptr=ptr->next;
    };
    return NULL;
};

template<typename T> void LinkedList<T>::print(){
    ListNode<T>* ptr=this->head;
    while(ptr){
        cout<<"<"<<ptr->data<<">\t"<<endl;
        ptr=ptr->next;
    }
}

template<typename T> long unsigned int LinkedList<T>::length(){
    ListNode<T>* ptr=this->head;
    long unsigned int len=0;
    while(ptr){
        len++;
        ptr=ptr->next;
    };
    return len;
};

template<typename T> LinkedList<T>::~LinkedList(){
    ListNode<T>* ptr=this->head;
    while (ptr){
        ListNode<T>* ptrx=ptr->next;
        this->head=ptrx;
        delete ptr;
        ptr=ptrx;
    };
    this->head=this->tail=NULL;
}