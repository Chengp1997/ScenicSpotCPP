//
// Created by 陈格平 on 2023/1/29.
//

#ifndef SENICSPOTMANAGEMENT_MENU_H
#define SENICSPOTMANAGEMENT_MENU_H

#include "iostream"
#include "../scenicSpot/ScenicSpotGraph.h"
using namespace std;
class Menu {
private:
    static void dealChoice(int choice, ScenicSpotGraph graph);
    static void printMap(ScenicSpotGraph graph);
    static void searchSpot(ScenicSpotGraph graph);
    static void rankSpot(ScenicSpotGraph graph);
    static void findShortestPath(ScenicSpotGraph graph);
    static void spotGuidance(ScenicSpotGraph graph);
    static void printSpots(ScenicSpotGraph graph);
    static void printPath(ScenicSpotGraph graph);
    static void parkingRecord(ScenicSpotGraph graph);
    static void exit();
public:
    [[noreturn]] static void printMenu(ScenicSpotGraph graph);
};


#endif //SENICSPOTMANAGEMENT_MENU_H
