//
// Created by 陈格平 on 2023/1/24.
//

#include "LinkedListNode.h"

template<class T>
void LinkedListNode<T>::setData(T data) {
    this->data = data;
}

template<class T>
T LinkedListNode<T>::getData() {return this->data;}