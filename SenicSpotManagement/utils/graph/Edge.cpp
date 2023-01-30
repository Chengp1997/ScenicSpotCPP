//
// Created by 陈格平 on 2023/1/26.
//

#include "Edge.h"
Edge::Edge(Vertex start, Vertex destination, int dis) {
    this->startSpot = start;
    this->destinationSpot = destination;
    this->distance = dis;
}

void Edge::setStartSpot(Vertex start) {
    this->startSpot = start;
}

void Edge::setDestinationSpot(Vertex destination) {
    this->destinationSpot = destination;
}

void Edge::setDistance(int dis) {
    this->distance = dis;
}

int Edge::getDistance() const {
    return distance;
}

Vertex Edge::getDestinationSpot() {
    return destinationSpot;
}

Vertex Edge::getStartSpot() {
    return startSpot;
}