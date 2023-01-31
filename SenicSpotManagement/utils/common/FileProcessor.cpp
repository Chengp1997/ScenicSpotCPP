//
// Created by 陈格平 on 2023/1/29.
//

#include "FileProcessor.h"
#include <vector>

vector<string> FileProcessor::readIn(const string& path) {

    ifstream  infile;
    infile.open(path);

    if (!infile.is_open()){
        cout<< "Could not open file "<<path<<endl;
        throw runtime_error("file open failed");
    }


    vector<string> data;
    string text;
    while (getline(infile,text)){
        data.push_back(text);
//        cout<<text<<endl;
    }
    infile.close();
    return data;
}

void FileProcessor::writeTo() {
    ofstream newFile;
    newFile.open("example.txt");
    newFile<<" writing to find path "<<endl;
    newFile.close();
}