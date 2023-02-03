//
// Created by 陈格平 on 2023/1/27.
//

#ifndef SENICSPOTMANAGEMENT_UTILS_H
#define SENICSPOTMANAGEMENT_UTILS_H
#include <vector>
#include <string>
#include "iostream"
using namespace std;

class Utils {

public:
    static string getCurrentTime();
    static vector<string> split(const string& toSplit);
};


#endif //SENICSPOTMANAGEMENT_UTILS_H
