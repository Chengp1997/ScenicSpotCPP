//
// Created by 陈格平 on 2023/1/29.
//

#ifndef SENICSPOTMANAGEMENT_FILEPROCESSOR_H
#define SENICSPOTMANAGEMENT_FILEPROCESSOR_H
#include "string"
#include "fstream"
#include "iostream"
using namespace std;

class FileProcessor {
public:
    static void readIn(string path);
    void writeTo();
};


#endif //SENICSPOTMANAGEMENT_FILEPROCESSOR_H
