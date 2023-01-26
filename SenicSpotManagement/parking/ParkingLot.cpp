//
// Created by 陈格平 on 2023/1/24.
//

#include "ParkingLot.h"
#include "iostream"

ParkingLot::ParkingLot() {
    this->size = 10;
}
ParkingLot::ParkingLot(int size) { this->size = size;}

void ParkingLot::park(string carId, string arriveTime) {
    Car toEnter(carId, arriveTime);
    //check if already exist
    auto iter = record.find(carId);
    if (record.find(carId)==record.end()){ //already exist
        if(iter->second.getStatus() == Car::INLOT){//in parking lot
            cout<< "already in lot -- error input"<< endl;
            return;
        }
    }

    record.insert(carId, toEnter);
    //not exist, input the car
    for(int i=0;i<parkingSpace.size();i++){
        //if parking lot is full
        if (parkingSpace.size() == this->size){
            cout<< "******Parking Log is Full, go to waiting line****"<<endl;
            waitingLine.push(toEnter);

        }else{

        }
    }
}

void ParkingLot::leave(string carId, string leaveTime) {

}

void ParkingLot::showParkingLot() {

}