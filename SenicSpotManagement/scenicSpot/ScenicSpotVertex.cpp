//
// Created by 陈格平 on 2023/1/28.
//

#include "ScenicSpotVertex.h"


ScenicSpotVertex::ScenicSpotVertex(string spotName,
                                   string intro, int welcome,
                                   bool relaxPlace, bool restRoom,
                                   int popularRanking) {
    this->spotName = spotName;
    this->intro = intro;
    this->welcome = welcome;
    this->relaxPlace = relaxPlace;
    this->restRoom = restRoom;
}

void ScenicSpotVertex::setSpotName(string name) {
    this->spotName = name;
}

void ScenicSpotVertex::setIntro(string introInfo) {
    this->intro = introInfo;
}

void ScenicSpotVertex::setWelcome(int welcomeWeight) {
    this->welcome = welcomeWeight;
}

void ScenicSpotVertex::setRelaxPlace(bool hasRelaxPlace) {
    this->relaxPlace = hasRelaxPlace;
}

void ScenicSpotVertex::setRestRoom(bool hasRestRoom) {
    this->restRoom = hasRestRoom;
}

string ScenicSpotVertex::getSpotName() {
    return spotName;
}

string ScenicSpotVertex::getIntro() {
    return intro;
}

int ScenicSpotVertex::getWelcome() const {
    return welcome;
}

bool ScenicSpotVertex::hasRelaxPlace() const {
    return relaxPlace;
}

bool ScenicSpotVertex::hasRestRoom() const {
    return restRoom;
}

void ScenicSpotVertex::toString() {
    cout<<"*********************************"<<endl;
    cout<<"\tspot name: "<<spotName<<endl;
    cout<<"\tStates: "<<intro<< endl;
    cout<<"\tWelcome weight: "<< welcome<<endl;
    cout<<"\tHas Relax Place: "<<relaxPlace<<endl;
    cout<<"\tHas Rest Room: "<<restRoom<<endl;
    cout<<"*********************************"<<endl;
}

