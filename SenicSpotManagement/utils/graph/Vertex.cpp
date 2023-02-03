//
// Created by 陈格平 on 2023/1/26.
//

#include "Vertex.h"

vector<Edge*>* Vertex::getEdges() {
    return edgeList;
}

int Vertex::getIndex() {
    return index;
}

void Vertex::setIndex(int i) {
    this->index = i;
}