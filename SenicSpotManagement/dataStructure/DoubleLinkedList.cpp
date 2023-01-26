//
// Created by 陈格平 on 2023/1/23.
//

#include "DoubleLinkedList.h"
template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = new LinkedListNode<T>();
    tail = new LinkedListNode<T>();

    head->prev = nullptr;
    head->next = nullptr;

}
