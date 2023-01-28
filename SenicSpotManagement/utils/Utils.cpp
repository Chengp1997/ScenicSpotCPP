//
// Created by 陈格平 on 2023/1/27.
//

#include "Utils.h"

string Utils::getCurrentTime() {
    time_t rawtime;
    time(&rawtime);
    return ctime(&rawtime);
}
