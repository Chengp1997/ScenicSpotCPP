//
// Created by 陈格平 on 2023/1/24.
//

#ifndef SENICSPOTMANAGEMENT_PARKINGLOT_H
#define SENICSPOTMANAGEMENT_PARKINGLOT_H
#include <stack>
#include <queue>
#include <map>
#include "Car.h"

using namespace std;

class ParkingLot {
private:
    int size;//size of the parking lot
    stack<Car> parkingSpace;
    stack<Car> bufferStack;
    queue<Car> waitingLine;
    map<string, Car> record;

public:
    ParkingLot();
    ParkingLot(int size);
    void park(string carId, string arriveTime);
    void leave(string carId, string leaveTime);
    void showParkingLot();
};


#endif //SENICSPOTMANAGEMENT_PARKINGLOT_H
