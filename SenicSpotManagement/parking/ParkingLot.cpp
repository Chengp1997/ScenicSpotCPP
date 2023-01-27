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
    Car currCar = toEnter;
        // check if already exist
    auto iter = record.find(carId);
    if (record.find(carId)==record.end()){ //already exist
        if(iter->second.getStatus() == Car::INLOT){//in parking lot
            cout<< "already in lot -- error input"<< endl;
            return;
        }
    }

    record.insert(std::make_pair(carId, currCar));
    //not exist, input the car
    for(int i=0;i<parkingSpace.size();i++){
        //if parking lot is full
        if (parkingSpace.size() == this->size){
            cout<< "******Parking Lot is Full, go to waiting line****"<<endl;
            waitingLine.push(toEnter);

        }else{
            // get curr time 之后给分出来 太他妈丑了
            time_t rawtime;
            time(&rawtime);
            currCar.setStartTime(ctime(&rawtime));
            //
            parkingSpace.push(currCar);
            cout << "******New car" + carId + "entered****" << endl;
        }
    }
}

void ParkingLot::leave(string carId, string leaveTime) {
    //find already exists id

    auto iter = record.find(carId);
    Car currCar = iter->second;

                  // if the car doesn't exist
    if (record.find(carId) != record.end())
    {
        cout<<"Invalid Car ID, Police on the way"<<endl;
    }
    time_t rawtime;
    time(&rawtime);
    currCar.setStatus(Car::INLOT); // gone status
    currCar.setEndTime(ctime(&rawtime));
    parkingSpace.pop();
}

void ParkingLot::showParkingLot() {

}

