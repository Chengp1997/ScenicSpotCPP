//
// Created by 陈格平 on 2023/1/26.
//

#include "Graph.h"

//initial
void Graph::initGraph() {

}



void Graph::printGraph() {
    for(int i=0;i<nodes.length();i++){

    }
}

void Graph::toAdjacencyMatrix() {
    //initialize adjacency matrix
    int size = nodes.length();
    adjacencyMatrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        adjacencyMatrix[i] = new int [size];
    }

    //not connected -- set to 32767
    //itself - 0
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            adjacencyMatrix[i][j] = 32767;
            if (i == j) adjacencyMatrix[i][j] = 0;
        }
    }
    
    //set distance between nodes
    for (int i = 0; i < size; ++i) {//for all nodes
        for (int j = 0; j < nodes.get(i).; ++j) {
            
        }
    }
}
