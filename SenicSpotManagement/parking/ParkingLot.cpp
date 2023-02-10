//
// Created by 陈格平 on 2023/1/24.
//

#include "ParkingLot.h"

ParkingLot::ParkingLot() {
    this->size = 10;
}
ParkingLot::ParkingLot(int size) { this->size = size;}

void ParkingLot::park(const string& carId) {
    // check if already exist
    auto iter = record.find(carId);
    if ( iter!=record.end()){ //already exist
        if(iter->second.getStatus() == Car::INLOT){//in parking lot
            cout<< "already in lot -- error input"<< endl;
            return;
        }
    }

    Car toEnter(carId);
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
    showParkingLot();
}

void ParkingLot::leave(const string& carId) {
    //check if exist
    auto iter = record.find(carId);
    if ( iter!=record.end()){ //exist
        Car toGO = iter->second;
        //in parking lot //INLOT, OUTLOT, WAITING
        if (toGO.getStatus() == Car::INLOT){
            while (!parkingSpace.isEmpty()){
                Car tempCar = parkingSpace.pop();

                //leave the parking space
                if (tempCar.getCarId() == toGO.getCarId()){//it's the one leaving
                    tempCar.setEndTime(Utils::getCurrentTime());
                    //push back
                    while (!bufferStack.isEmpty()){
                        Car temp = bufferStack.pop();
                        parkingSpace.push(temp);
                    }
                    //set status to store in record
                    tempCar.setStatus(Car::OUTLOT);
                    record.insert(std::make_pair(carId,tempCar));

                    cout<<"car "<<tempCar.getCarId()<<" is leaving the parkingLot"<<endl;
                    cout<<"leaving time is: "<<tempCar.getEndTime()<<endl;

                    break;
                } else{
                    bufferStack.push(tempCar);
                }
            }
            //push the first car in waiting line in the parking lot if there is
            if (!waitingLine.isEmpty()){
                Car tempCar = waitingLine.poll();
                tempCar.setStatus(Car::INLOT);
                parkingSpace.push(tempCar);

                record.insert(make_pair(carId,tempCar));

                cout<<"car "<<tempCar.getCarId()<<" in waiting line is entering the parking log"<<endl;
            }

            showParkingLot();
        } else if (toGO.getStatus() == Car::OUTLOT){
            cout<<"*****error input, it's not in the parking lot"<<endl;
        } else{
            cout<<"*****error input, it's in line"<<endl;
        }

    }else{
        cout<< "*******error input , No this car in record****"<<endl;
    }


}

void ParkingLot::showParkingLot() {
    cout<< "******showing current status*********"<<endl;
    cout<< "***parking lot size: "<< parkingSpace.size()<<endl;
    cout<< "***waiting line size: "<< waitingLine.size()<<endl;
    cout<< "***buffer size: "<< bufferStack.size()<<endl;
}

