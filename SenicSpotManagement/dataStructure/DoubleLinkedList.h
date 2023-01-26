//
// Created by 陈格平 on 2023/1/23.
//

#ifndef SENICSPOTMANAGEMENT_DOUBLELINKEDLIST_H
#define SENICSPOTMANAGEMENT_DOUBLELINKEDLIST_H
#include "LinkedListNode.h"

template<class T>
class DoubleLinkedList {
private:
    int size;
    LinkedListNode<T>* head;
    LinkedListNode<T>* tail;
public:
    DoubleLinkedList();
    bool isEmpty();
    int getSize();
    void append(T data);
    void prepend(T data);
    void remove(int index);
    void removeTail();
    void removeHead();
};


#endif //SENICSPOTMANAGEMENT_DOUBLELINKEDLIST_H
