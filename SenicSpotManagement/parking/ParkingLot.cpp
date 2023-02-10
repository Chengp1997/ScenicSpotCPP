//
// Created by 陈格平 on 2023/1/24.
//

#include "ParkingLot.h"

ParkingLot::ParkingLot(int size) {
    this->size = size;
    parkingSpace = new Stack<Car*>(size);
    bufferStack = new Stack<Car*>;
    waitingLine = new Queue<Car*>;
    record = new map<string, Car*>;
}

void ParkingLot::park(const string& carId) {
    // check if already exist
    auto iter = record->find(carId);
    if ( iter!=record->end()){ //already exist
        if(iter->second->getStatus() == Car::INLOT){//in parking lot
            cout<< "already in lot -- error input"<< endl;
            return;
        }
    }

    Car* toEnter = new Car(carId);
        //if parking lot is full
        if (parkingSpace->isFull()){
            toEnter->setStatus(Car::WAITING);
            waitingLine->offer(toEnter);
            cout<< "******Parking Lot is Full, go to waiting line****"<<endl;
            cout<< "******Car"<<carId<<" entering the waiting line***"<<endl;
        }else{
            toEnter->setStartTime(Utils::getCurrentTime());
            toEnter->setStatus(Car::INLOT);
            parkingSpace->push(toEnter);
            cout<<parkingSpace->size();
            cout << "******New car" + carId + "entered parking lot****" << endl;
        }
    //record
    record->insert(std::make_pair(carId, toEnter));
    showParkingLot();
}

void ParkingLot::leave(const string& carId) {
    //check if exist
    auto iter = record->find(carId);
    if ( iter!=record->end()){ //exist
        Car* toGO = iter->second;
        //in parking lot //INLOT, OUTLOT, WAITING
        if (toGO->getStatus() == Car::INLOT){
            while (!parkingSpace->isEmpty()){
                Car* tempCar = parkingSpace->pop();

                //leave the parking space
                if (tempCar->getCarId() == toGO->getCarId()){//it's the one leaving
                    tempCar->setEndTime(Utils::getCurrentTime());
                    //push back
                    while (!bufferStack->isEmpty()){
                        Car* temp = bufferStack->pop();
                        parkingSpace->push(temp);
                    }
                    //set status to store in record
                    tempCar->setStatus(Car::OUTLOT);
                    record->insert(std::make_pair(carId,tempCar));

                    cout<<"car "<<tempCar->getCarId()<<" is leaving the parkingLot"<<endl;
                    cout<<"leaving time is: "<<tempCar->getEndTime()<<endl;

                    break;
                } else{
                    bufferStack->push(tempCar);
                }
            }
            //push the first car in waiting line in the parking lot if there is
            if (!waitingLine->isEmpty()){
                Car* tempCar = waitingLine->poll();
                tempCar->setStatus(Car::INLOT);
                parkingSpace->push(tempCar);

                record->insert(make_pair(carId,tempCar));

                cout<<"car "<<tempCar->getCarId()<<" in waiting line is entering the parking log"<<endl;
            }

            showParkingLot();
        } else if (toGO->getStatus() == Car::OUTLOT){
            cout<<"\t\t\terror input, it's not in the parking lot\n"<<endl;
        } else{
            cout<<"\t\t\terror input, it's in line\n"<<endl;
        }

    }else{
        cout<< "\t\t\terror input , No this car in record\n"<<endl;
    }


}

void ParkingLot::showParkingLot() {
    cout<< "\n******showing current status*********"<<endl;
    cout<< "\t\tparking lot size: "<< parkingSpace->size()<<endl;
    cout<< "\t\twaiting line size: "<< waitingLine->size()<<endl;
    cout<< "\t\tbuffer size: "<< bufferStack->size()<<endl;
    cout<< "******showing current status*********\n"<<endl;
}

