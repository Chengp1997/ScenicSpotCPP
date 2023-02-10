//
// Created by 陈格平 on 2023/1/29.
//

#ifndef SENICSPOTMANAGEMENT_MENU_H
#define SENICSPOTMANAGEMENT_MENU_H

#include <vector>
#include "iostream"
#include "../scenicSpot/ScenicSpotGraph.h"
#include "../utils/algorithm/Sorting.h"
#include "../utils/algorithm/MST.h"
#include "../parking/ParkingLot.h"

using namespace std;
class Menu {
private:
    ScenicSpotGraph graph;
    ParkingLot parkingLot;
    void dealChoice(int choice);
    void printMap();
    void searchSpot();
    void rankSpot();
    void findShortestPath();
    void spotGuidance();
    void printSpots();
    void printPath();
    void printParkingMenu();
    static void exit();
public:
    Menu() = default;;
    [[noreturn]]  void printMenu();
};


#endif //SENICSPOTMANAGEMENT_MENU_H
