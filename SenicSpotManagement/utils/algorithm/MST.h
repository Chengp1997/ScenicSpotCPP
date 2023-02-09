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
    void kruskal(ScenicSpotGraph graph);
    static void printPath(vector<ScenicSpotVertex> path, vector<int> sum);
public:
    static void generateGuidance(const std::string& start, ScenicSpotGraph graph);
};


#endif //SENICSPOTMANAGEMENT_MST_H
