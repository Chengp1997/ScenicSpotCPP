//
// Created by 陈格平 on 2023/1/26.
//

#include "Edge.h"
Edge::Edge(string start, string destination, int dis) {
    this->startSpotName = start;
    this->destinationSpotName = destination;
    this->distance = dis;
}

void Edge::setStartSpot(string start) {
    this->startSpotName = start;
}

void Edge::setDestinationSpot(string destination) {
    this->destinationSpotName = destination;
}

void Edge::setDistance(int dis) {
    this->distance = dis;
}

int Edge::getDistance() const {
    return distance;
}

string Edge::getDestinationSpot() {
    return destinationSpotName;
}

string Edge::getStartSpot() {
    return startSpotName;
}