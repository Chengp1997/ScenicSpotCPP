//
// Created by 陈格平 on 2023/1/28.
//

#include "ScenicSpotVertex.h"

void ScenicSpotVertex::setSpotName(string spotName) {
    this->spotName = spotName;
}

void ScenicSpotVertex::setIntro(string intro) {
    this->intro = intro;
}

void ScenicSpotVertex::setWelcome(int welcome) {
    this->welcome = welcome;
}

void ScenicSpotVertex::setRelaxPlace(bool relaxPlace) {
    this->relaxPlace = relaxPlace;
}

void ScenicSpotVertex::setRestRoom(bool restRoom) {
    this->restRoom = restRoom;
}

string ScenicSpotVertex::getSpotName() {
    return spotName;
}

string ScenicSpotVertex::getIntro() {
    return intro;
}

int ScenicSpotVertex::getWelcome() {
    return welcome;
}

bool ScenicSpotVertex::hasRelaxPlace() {
    return relaxPlace;
}

bool ScenicSpotVertex::hasRestRoom() {
    return restRoom;
}