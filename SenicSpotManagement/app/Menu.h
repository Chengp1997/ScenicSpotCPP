//
// Created by 陈格平 on 2023/1/29.
//

#ifndef SENICSPOTMANAGEMENT_MENU_H
#define SENICSPOTMANAGEMENT_MENU_H

#include "iostream"
#include "../scenicSpot/Graph.h"
using namespace std;
class Menu {
private:
    static void dealChoice(int choice, Graph graph);
    static void printMap(Graph graph);
    static void searchSpot(Graph graph);
    static void rankSpot(Graph graph);
    static void findShortestPath(Graph graph);
    static void spotGuidance(Graph graph);
    static void printSpots(Graph graph);
    static void printPath(Graph graph);
    static void parkingRecord(Graph graph);
    static void exit();
public:
    [[noreturn]] static void printMenu(Graph graph);
};


#endif //SENICSPOTMANAGEMENT_MENU_H
