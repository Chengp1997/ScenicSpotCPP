//
// Created by 陈格平 on 2023/1/26.
//

#include "ScenicSpotGraph.h"

//initial
void ScenicSpotGraph::initGraph() {
    //read from file
    vector<string> spotInfo = FileProcessor::readIn(VertexPath);
    vector<string> edgeInfo = FileProcessor::readIn(EdgesPath);
    //

    toAdjacencyMatrix();
}


void ScenicSpotGraph::toAdjacencyMatrix() {
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
        Vertex vertex = * nodes.get(i);
        for (int j = 0; j < vertex.getEdges().length(); ++j) {
            Edge edge = * vertex.getEdges().get(i);
            adjacencyMatrix[i][j] = edge.getDistance();
        }
    }

    printMatrix();
}

void ScenicSpotGraph::printMatrix() {//print adjacency matrix
    for (int i = 0; i < nodes.length(); ++i) {
        ScenicSpotVertex vertex = *nodes.get(i);
        cout<< vertex.getSpotName() <<"\t";
    }
    cout<<endl;

    for(int i=0;i<nodes.length();i++){
        ScenicSpotVertex vertex = *nodes.get(i);
        for (int j = 0; j < vertex.getEdges().length(); ++j) {
            if (j == 0) cout<< vertex.getSpotName()<< " ";
            cout<<adjacencyMatrix[i][j]<<"\t";
            if(j == nodes.length()) cout<<endl;
        }

    }
}

void ScenicSpotGraph::printGraph() {

}

ScenicSpotVertex* ScenicSpotGraph::searchSpot(const string& searchName) {
    int index = -1;
    for (int i = 0; i < nodes.length(); ++i) {
        if (nodes.get(i)->getSpotName()==searchName){
            index = i;
            break;
        }
    }
    if (index == -1) {
        return nullptr;
    }
    ScenicSpotVertex* spot = nodes.get(index);
    return spot;
}
