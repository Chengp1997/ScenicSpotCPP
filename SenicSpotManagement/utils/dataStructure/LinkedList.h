//
// Created by 陈格平 on 2023/1/28.
//

#ifndef SENICSPOTMANAGEMENT_LINKEDLIST_H
#define SENICSPOTMANAGEMENT_LINKEDLIST_H
#include "iostream"
using namespace std;

template<class T>
struct Node {
public:
    T data;// data field
    Node<T>* next; //pointer to next node
    //constructor
    Node(Node<T>* ptr = nullptr){next = ptr;}//initial ptr is null
    Node(T val, Node<T> *ptr= nullptr){
        data = val;
        next = ptr;
    }
};

template<class T>
class LinkedList {
private:
    Node<T>* head;
    int listSize;
public:
    LinkedList(){
        head = new Node<T>;
        listSize = 0;
    };
    LinkedList(T &val){
        head = new Node<T>(val);
        listSize = 0;
    };
//    ~LinkedList(){clear();}
    void clear();

    Node<T>* find(int index);
    T* get(int index);
    void pushFront(T val);
    void pushBack(T val);
    void push(int index, T val);
//    void push(int index,Node<T>* newNode);
    void removeFront();
    void removeTail();
    void remove(int index);
    int size();
    void displayAll();

    bool isEmpty();
};

template<class T>
void LinkedList<T>::clear() {
    Node<T>* current = head;
    while (head!= nullptr){
        head = head->next;
        delete current;
        current = head;
    }
}

template<class T>
Node<T> *LinkedList<T>::find(int index) {
    if (index < 0 || index >= listSize)return NULL;
    Node<T>* current = head;
    for(int i=0;i<index;i++){
        current = current->next;
    }
    return current;
}

template<class T>
T* LinkedList<T>::get(int index) {
    Node<T> * p = find(index);
    if (p == NULL) return NULL;
    return &(p->data);
}

template<class T>
void LinkedList<T>::pushFront(T val) {
    push(0, val);
}

template<class T>
void LinkedList<T>::pushBack(T val) {
    push(listSize, val);
}

//template<class T>
//void LinkedList<T>::push(int index, T &val) {
//    if(index<0||index>listSize) return;
//
//    auto* newNode = new Node<T>(val);
//    this->push(newNode);
//    newNode = nullptr;
//}
//
//template<class T>
//void LinkedList<T>::push(int index,Node<T>* newNode) {
//    Node<T>* current = head;
//    if(index == 0){
//        newNode->next = head;
//        head = newNode;
//    } else{
//        for(int i=0;i<index-1;i++){
//            current = current->next;
//        }
//        newNode->next = current->next;
//        current->next = newNode;
//    }
//    listSize++;
//}

template<class T>
void LinkedList<T>::push(int index, T val) {
    if(index<0|| index > listSize) return;

    auto* newNode = new Node<T>(val);
    Node<T>* current = head;
    if(index == 0){
        newNode->next = head;
        head = newNode;
    } else{
        for(int i=0;i<index-1;i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    listSize++;
}


template<class T>
void LinkedList<T>::removeFront() {
    remove(0);
}

template<class T>
void LinkedList<T>::removeTail() {
    remove(size() - 1);
}

template<class T>
void LinkedList<T>::remove(int index) {
    if(index<0|| index >= listSize) return;

    if(index == 0){
        Node<T>* nextNode = head->next;
        delete head;
        head = nextNode;
    } else{
        Node<T>* current = head;
        for(int i=0;i<index-1;i++){
            current = current->next;
        }
        Node<T>* nextNode = current->next->next;
        delete current->next;
        current->next = nextNode;
    }
    listSize--;
}

template<class T>
int LinkedList<T>::size() {
    return listSize;
}

template<class T>
void LinkedList<T>::displayAll() {
    Node<T>* current = head;
    int i = 0;
    while (current->next!=NULL){
        cout<<current->data<<" ";
        if (++i%10 == 0)cout<<endl;
        current = current->next;
    }
    cout<< endl;
}

template<class T>
bool LinkedList<T>::isEmpty() {return listSize == 0;}


#endif //SENICSPOTMANAGEMENT_LINKEDLIST_H
