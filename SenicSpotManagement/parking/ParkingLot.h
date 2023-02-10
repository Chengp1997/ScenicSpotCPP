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
    int size;//listSize of the parking lot
    Stack<Car*>* parkingSpace;
    Stack<Car*>* bufferStack;
    Queue<Car*>* waitingLine;
    map<string, Car*>* record;

public:
    ParkingLot(){
        this->size = 10;
        parkingSpace = new Stack<Car*>(this->size);
        bufferStack = new Stack<Car*>;
        waitingLine = new Queue<Car*>;
        record = new map<string, Car*>;
    };
    ParkingLot(int size);
    void park(const string& carId);
    void leave(const string& carId);
    void showParkingLot();
};


#endif //SENICSPOTMANAGEMENT_PARKINGLOT_H
