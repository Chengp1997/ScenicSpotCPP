//
// Created by 陈格平 on 2023/1/24.
//

#ifndef SENICSPOTMANAGEMENT_PARKINGLOT_H
#define SENICSPOTMANAGEMENT_PARKINGLOT_H
#include <map>
#include "iostream"
#include "Car.h"
#include "../utils/common/Utils.h"
#include "../utils/dataStructure/Stack.h"
#include "../utils//dataStructure/Queue.h"

using namespace std;

class ParkingLot {
private:
    int size;//size of the parking lot
    Stack<Car> parkingSpace;
    Stack<Car> bufferStack;
    Queue<Car> waitingLine;
    map<string, Car> record;

public:
    ParkingLot();
    ParkingLot(int size);
    void park(string carId);
    void leave(string carId);
    void showParkingLot();
};


#endif //SENICSPOTMANAGEMENT_PARKINGLOT_H
