//
// Created by 陈格平 on 2023/2/2.
//

#ifndef SENICSPOTMANAGEMENT_SHORTESTPATH_H
#define SENICSPOTMANAGEMENT_SHORTESTPATH_H
#include <vector>
#include "../graph/Vertex.h"
#include "../../scenicSpot/ScenicSpotGraph.h"

class ShortestPath {
private:
     static void Dijkstra(int start, int shortestPath[], int distance[], ScenicSpotGraph graph);
     static void Dijkstra(Vertex start, Vertex end, ScenicSpotGraph graph);
     static void Floyd(Vertex start, Vertex end, ScenicSpotGraph graph);
     static void Floyd(int** path, int** distance, ScenicSpotGraph graph);
     static void printPath(vector<ScenicSpotVertex> roads, int distance[]);
public:
     static void findShortestRoad(const string& start, const string& des, ScenicSpotGraph graph);
};


#endif //SENICSPOTMANAGEMENT_SHORTESTPATH_H
