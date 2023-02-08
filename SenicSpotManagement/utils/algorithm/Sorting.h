//
// Created by 陈格平 on 2023/2/1.
//

#ifndef SENICSPOTMANAGEMENT_SORTING_H
#define SENICSPOTMANAGEMENT_SORTING_H
#include<vector>
#include "../../scenicSpot/ScenicSpotVertex.h"

class Sorting {
private:
    static void insertionSort(vector<ScenicSpotVertex> &spots, int move);
    static void merge(vector<ScenicSpotVertex> &spots, int start, int mid, int end);
    void mergeSort(vector<ScenicSpotVertex> &spots, int start, int end);
    static void quickSort(vector<ScenicSpotVertex> &spots, int start, int end);
public:
    static void bubbleSort(vector<ScenicSpotVertex> &spots);
    static void selectionSort(vector<ScenicSpotVertex> &spots);
    static void insertionSort(vector<ScenicSpotVertex> &spots);
    void mergeSort(vector<ScenicSpotVertex> &spots);
    static void quickSort(vector<ScenicSpotVertex> &spots);
    static void shellSort(vector<ScenicSpotVertex> &spots);
};


#endif //SENICSPOTMANAGEMENT_SORTING_H
