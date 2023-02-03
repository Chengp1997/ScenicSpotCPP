//
// Created by 陈格平 on 2023/1/24.
//

#include "ParkingLot.h"

ParkingLot::ParkingLot() {
    this->size = 10;
}
ParkingLot::ParkingLot(int size) { this->size = size;}

void ParkingLot::park(string carId) {
    // check if already exist
    auto iter = record.find(carId);
    if ( iter!=record.end()){ //already exist
        if(iter->second.getStatus() == Car::INLOT){//in parking lot
            cout<< "already in lot -- error input"<< endl;
            return;
        }
    }

    Car toEnter(carId);
//    Car currCar = toEnter;
    //not in parking lot, enter!
    for(int i=0;i<parkingSpace.size();i++){
        //if parking lot is full
        if (parkingSpace.size() == this->size){
            toEnter.setStatus(Car::WAITING);
            waitingLine.offer(toEnter);
            cout<< "******Parking Lot is Full, go to waiting line****"<<endl;
            cout<< "******Car"<<carId<<" entering the waiting line***"<<endl;
        }else{
            toEnter.setStartTime(Utils::getCurrentTime());
            parkingSpace.push(toEnter);
            cout << "******New car" + carId + "entered parking lot****" << endl;
        }
    }
    //record
    record.insert(std::make_pair(carId, toEnter));
}

void ParkingLot::leave(string carId) {
    //check if exist
    auto iter = record.find(carId);
    if ( iter!=record.end()){ //exist
        Car toGO = iter->second;
        //in parking lot

    }

    cout<< "*******error input , no this car****"<<endl;

}

void ParkingLot::showParkingLot() {
    cout<< "******showing current status*********"<<endl;
    cout<< "***parking lot size: "<< parkingSpace.size()<<endl;
    cout<< "***waiting line size: "<< waitingLine.size()<<endl;
    cout<< "***buffer size: "<< bufferStack.size()<<endl;
}

