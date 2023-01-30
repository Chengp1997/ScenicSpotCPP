//
// Created by 陈格平 on 2023/1/26.
//

#ifndef SENICSPOTMANAGEMENT_VERTEX_H
#define SENICSPOTMANAGEMENT_VERTEX_H
#include "../dataStructure/LinkedList.h"

class Edge;
class Vertex {
private:
    LinkedList<Edge> edgeList;
public:
    Vertex()= default;

    LinkedList<Edge> getEdges();
};


#endif //SENICSPOTMANAGEMENT_VERTEX_H
