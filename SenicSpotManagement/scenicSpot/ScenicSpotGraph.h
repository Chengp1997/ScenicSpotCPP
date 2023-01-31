//
// Created by 陈格平 on 2023/1/26.
//

#ifndef SENICSPOTMANAGEMENT_SCENICSPOTGRAPH_H
#define SENICSPOTMANAGEMENT_SCENICSPOTGRAPH_H
#include "ScenicSpotVertex.h"
#include "../utils/common/FileProcessor.h"
#include <vector>

using namespace std;

class ScenicSpotGraph {
private:
    string EdgesPath = "files/spots.txt";
    string VertexPath = "files/spotsInfo.txt";
    LinkedList<ScenicSpotVertex> nodes;
    int** adjacencyMatrix ;

    void initGraph();//initialize graph to adjacency matrix
    void toAdjacencyMatrix();
    void printMatrix();
public:
    ScenicSpotGraph(){
        initGraph();
    };

    void printGraph();//print current adjacency matrix
    ScenicSpotVertex* searchSpot(const string& searchName);
};


#endif //SENICSPOTMANAGEMENT_SCENICSPOTGRAPH_H
