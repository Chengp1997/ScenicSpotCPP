//
// Created by 陈格平 on 2023/2/8.
//

#ifndef SENICSPOTMANAGEMENT_MST_H
#define SENICSPOTMANAGEMENT_MST_H
#include <string>
#include <vector>
#include "../../scenicSpot/ScenicSpotGraph.h"


class MST {
private:
    static void prim(int start, ScenicSpotGraph graph);
    static void printPath(vector<ScenicSpotVertex> path, vector<int> sum);
    static bool hamiltonCircuitDfs(int path[], bool used[], int step, ScenicSpotGraph graph);
public:
    static void hamiltonCircuit(ScenicSpotGraph graph);
};


#endif //SENICSPOTMANAGEMENT_MST_H
