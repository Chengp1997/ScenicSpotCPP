//
// Created by 陈格平 on 2023/1/26.
//

#ifndef SENICSPOTMANAGEMENT_EDGE_H
#define SENICSPOTMANAGEMENT_EDGE_H
#include "Vertex.h"

class Edge {
private:
    int distance;
    Vertex startSpot;
    Vertex destinationSpot;
public:
    explicit Edge(int dis = 0){distance = dis;};
    Edge(Vertex start, Vertex destination, int distance = 0);

    int getDistance() const;
    Vertex getStartSpot();
    Vertex getDestinationSpot();

    void setDistance(int dis);
    void setStartSpot(Vertex start);
    void setDestinationSpot(Vertex destination);
};

#endif //SENICSPOTMANAGEMENT_EDGE_H
