//
// Created by 陈格平 on 2023/1/27.
//

#ifndef SENICSPOTMANAGEMENT_STACK_H
#define SENICSPOTMANAGEMENT_STACK_H
#include "iostream"
using namespace std;
//default capacity
#define SIZE 10

template<class T>
class Stack {
private:
    T *data;
    int top;
    int capacity;// how
public:
    Stack(int size = SIZE);
    ~Stack();

    void push(T data);
    T pop();
    T peek();

    int size();
    bool isEmpty();
    bool isFull();
};

template<class T>
Stack<T>::Stack(int size){
    data = new T[size];
    capacity = size;
    top = -1;
}

template<class T>
Stack<T>::~Stack<T>() {
    delete[] data;
}

template<class T>
void Stack<T>::push(T val) {
    if (isFull()){
        cout << "stack is full!"<<endl;
    }else{
        data[++top] = val;
    }
}

template<class T>
T Stack<T>::pop() {
    if (isEmpty()){
        cout<< "stack is empty! failed!"<<endl;
        throw runtime_error("Error: stack is empty");
    }else{
        return data[top--];
    }
}

template<class T>
T Stack<T>::peek() {
    if (isEmpty()){
        cout<< "stack is Empty! failed"<<endl;
        throw runtime_error("Error: stack is empty");
    }else{
        return data[top];
    }
}

template<class T>
bool Stack<T>::isEmpty() {
    return size()==0;
}

template<class T>
bool Stack<T>::isFull() {
    return size() == capacity;
}

template<class T>
int Stack<T>::size() {
    return top+1;
}


#endif //SENICSPOTMANAGEMENT_STACK_H
