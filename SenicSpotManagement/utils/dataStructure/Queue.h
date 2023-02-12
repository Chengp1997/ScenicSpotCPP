//
// Created by 陈格平 on 2023/1/23.
//

#ifndef SENICSPOTMANAGEMENT_QUEUE_H
#define SENICSPOTMANAGEMENT_QUEUE_H
#include "iostream"
using namespace std;

template<class T>
class Queue {
#define QUEUESIZE 1000
private:
    T* data;//array to store the
    int capacity; //max listSize of the queue
    int front; //front pointer of the first element in the queue
    int rear; //rear pointer of the last element in the queue
    int count; //listSize of the queue
public:
    Queue(int size = QUEUESIZE);
    ~Queue();

    void offer(T val);
    T poll();
    T peek();
    int size();
    bool isEmpty();
    bool isFull();

    void displayAll();

};

template<class T>
Queue<T>::Queue(int size) {
    data = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

template<class T>
Queue<T>::~Queue<T>() {
    delete[] data;
}

template<class T>
void Queue<T>::offer(T val) {
    if (isFull()){
        cout << "queue is full!"<<endl;
        throw runtime_error("Error: queue is Full");
    }

    rear  = (rear+1)%capacity;
    data[rear] = val;
    count++;
}

template<class T>
T Queue<T>::poll() {
    if (isEmpty()){
        cout << "queue is empty!"<<endl;
        throw runtime_error("Failed: queue is empty");
    }
    T toReturn = data[front];
    front = (front + 1)%capacity;
    count --;
    return toReturn;
}

template<class T>
T Queue<T>::peek() {
    if (isEmpty()){
        cout << "queue is empty!"<<endl;
        throw runtime_error("Failed: queue is empty");
    }
    return data[front];
}

template<class T>
int Queue<T>::size() {
    return count;
}

template<class T>
bool Queue<T>::isEmpty() {
    return size()==0;
}

template<class T>
bool Queue<T>::isFull() {
    return size() == capacity;
}

template<class T>
void Queue<T>::displayAll() {
    for(int i=0;i<count;i++){
        cout<<data[i]<<" ";
        if(i!=0 && i%10==0) cout<<endl;
    }
    cout<<endl;
}

#endif //SENICSPOTMANAGEMENT_QUEUE_H
