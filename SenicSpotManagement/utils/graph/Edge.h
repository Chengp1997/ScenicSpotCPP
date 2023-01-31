//
// Created by 陈格平 on 2023/1/26.
//

#ifndef SENICSPOTMANAGEMENT_EDGE_H
#define SENICSPOTMANAGEMENT_EDGE_H
#include "string"
using namespace std;

class Edge {
private:
    int distance;
    string startSpotName;
    string destinationSpotName;
public:
    explicit Edge(int dis = 0){ distance = dis;};
    Edge(string start, string destination, int distance = 0);

    int getDistance() const;
    string getStartSpot();
    string getDestinationSpot();

    void setDistance(int dis);
    void setStartSpot(string start);
    void setDestinationSpot(string destination);
};

#endif //SENICSPOTMANAGEMENT_EDGE_H
