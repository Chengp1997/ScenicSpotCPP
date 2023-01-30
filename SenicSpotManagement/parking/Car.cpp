//
// Created by 陈格平 on 2023/1/23.
//

#include "Car.h"
#include <string>


Car::Car() {};

Car::Car(string carId) {
    this->carId = carId;
    this->status = OUTLOT;
}

string Car::getCarId() {
    return carId;
}

string Car::getStartTime() {
    return startTime;
}

string Car::getEndTime() {
    return endTime;
}

int Car::getStatus() {
    return status;
}

void Car::setStartTime(string startTime) {
    this->startTime = startTime;
}

void Car::setEndTime(string endTime) {
    this->endTime = endTime;
}

void Car::setStatus(int status) {
    this->status = status;
}

bool Car::equals(string carId) {
    return this->getCarId().compare(carId) == 0;
}