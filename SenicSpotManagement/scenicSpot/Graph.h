//
// Created by 陈格平 on 2023/1/26.
//

#ifndef SENICSPOTMANAGEMENT_GRAPH_H
#define SENICSPOTMANAGEMENT_GRAPH_H
#include "../utils/graph/Vertex.h"
//#include "../utils/dataStructure/LinkedList.h"

class Vertex;
class Edge;
class Graph {
private:
    string EdgesPath = "files/spots.txt";
    string VertexPath = "files/spotsInfo.txt";
    LinkedList<Vertex> nodes;
    int** adjacencyMatrix ;

    void initGraph();//initialize graph to adjacency matrix
    void toAdjacencyMatrix();

public:
    Graph(){
        initGraph();
    };
    void printGraph();//print current adjacency matrix

};


#endif //SENICSPOTMANAGEMENT_GRAPH_H
