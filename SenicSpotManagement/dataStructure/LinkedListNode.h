//
// Created by 陈格平 on 2023/1/24.
//

#ifndef SENICSPOTMANAGEMENT_LINKEDLISTNODE_H
#define SENICSPOTMANAGEMENT_LINKEDLISTNODE_H

template<class T>
class LinkedListNode {
private:
    T data;
public:
    LinkedListNode(){};
    LinkedListNode<T>* prev;
    LinkedListNode<T>* next;

    void setData(T data);
    T getData();
};


#endif //SENICSPOTMANAGEMENT_LINKEDLISTNODE_H
