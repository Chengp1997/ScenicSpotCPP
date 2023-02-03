//
// Created by 陈格平 on 2023/1/27.
//

#include "Utils.h"

string Utils::getCurrentTime() {
    time_t rawtime;
    time(&rawtime);
    return ctime(&rawtime);
}

vector<string> Utils::split(const string& toSplit) {
    char* s = new char[toSplit.size() + 1];
    strcpy(s, toSplit.c_str());
    char* p = strtok(s, " ");
    vector<string> words;
    while(p) {
        words.push_back(p);
        p = strtok(NULL, " ");
    }
    return words;
}
