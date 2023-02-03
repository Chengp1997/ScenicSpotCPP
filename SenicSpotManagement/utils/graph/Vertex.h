//
// Created by 陈格平 on 2023/1/26.
//

#ifndef SENICSPOTMANAGEMENT_VERTEX_H
#define SENICSPOTMANAGEMENT_VERTEX_H
#include "../dataStructure/LinkedList.h"
#include "Edge.h"
#include <vector>

class Vertex {
private:
    int index;
    vector<Edge*>* edgeList;
public:
    Vertex(){
        edgeList = new vector<Edge*>;
        index = -1;
    }

    vector<Edge*>* getEdges();
    int getIndex();
    void setIndex(int i);
};


#endif //SENICSPOTMANAGEMENT_VERTEX_H
