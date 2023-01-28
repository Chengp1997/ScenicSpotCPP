//
// Created by 陈格平 on 2023/1/23.
//

#ifndef SENICSPOTMANAGEMENT_CAR_H
#define SENICSPOTMANAGEMENT_CAR_H
#include <string>
using namespace std;

class Car {
private:
    string carId;
    string startTime;
    string endTime;
    int status;
public:

    Car();
    Car(string carId);

    bool equals(string carId);

    string getCarId();
    string getStartTime();
    string getEndTime();
    int getStatus();

    void setStartTime(string startTime);
    void setEndTime(string endTime);
    void setStatus(int status);

    enum { INLOT, OUTLOT, WAITING};
};


#endif //SENICSPOTMANAGEMENT_CAR_H
