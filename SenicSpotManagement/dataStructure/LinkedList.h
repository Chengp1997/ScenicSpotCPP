//
// Created by 陈格平 on 2023/1/28.
//

#ifndef SENICSPOTMANAGEMENT_LINKEDLIST_H
#define SENICSPOTMANAGEMENT_LINKEDLIST_H

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
    int size;
public:
    LinkedList(){
        head = new Node<T>;
        size = 0;
    };
    LinkedList(T &val){
        head = new Node<T>(val);
        size = 0;
    };
    ~LinkedList(){clear();}
    void clear();

    T get(int index);
    void addFront(T val);
    void addTail(T val);
    void add(int index, T val);
    void removeFront();
    void removeTail();
    void remove(int index);
    int length();
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
T LinkedList<T>::get(int index) {
    if (index < 0 || index>=size)return NULL;
    Node<T>* current = head;
    for(int i=0;i<index;i++){
        current = current->next;
    }
    return current;
}

template<class T>
void LinkedList<T>::addFront(T val) {
    add(0, val);
}

template<class T>
void LinkedList<T>::addTail(T val) {
    add(size,val);
}

template<class T>
void LinkedList<T>::add(int index, T val) {
    if(index<0||index>size) return;

    Node<T>* current = head;
    Node<T>* newNode = new Node<T>(val);
    //insert at head
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
    size++;
}

template<class T>
void LinkedList<T>::removeFront() {
    remove(0);
}

template<class T>
void LinkedList<T>::removeTail() {
    remove(length()-1);
}

template<class T>
void LinkedList<T>::remove(int index) {
    if(index<0||index>=size) return;

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
    size--;
}

template<class T>
int LinkedList<T>::length() {
    return size;
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
bool LinkedList<T>::isEmpty() {return size==0;}

#endif //SENICSPOTMANAGEMENT_LINKEDLIST_H
