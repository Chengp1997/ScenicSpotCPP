//
// Created by 陈格平 on 2023/2/1.
//

#include "Sorting.h"

/**
 * Time: (n-1)*n/2 - n^2
 * Space: in-place -> 1
 * @param spots
 */
void Sorting::bubbleSort(vector<ScenicSpotVertex> &spots) {
    for (int i = 0; i < spots.size()-1; ++i) {//total - n-1 times
        bool changed = false;//to check -- if no exchange means already sorted
        for (int j = 0; j < spots.size()-1-i; ++j) {//compare the len-i half of the array
            if (spots[j].getWelcome()>spots[j+1].getWelcome()){
                swap(spots[j],spots[j+1]);
                changed = true;
            }
            if(!changed) return;
        }
    }
}

/**
 * time: (n-1)*n/2 - n^2
 * space: in-place -1
 * @param spots
 */
void Sorting::selectionSort(vector<ScenicSpotVertex> &spots) {
    for (int i = 0; i < spots.size()-1; ++i) {
        int min_index = i;//position to be replaced
        for (int j = 1; j < spots.size()-1; ++j) {// find the min at the remaining
            if (spots[j].getWelcome()<spots[min_index].getWelcome()){
                min_index = j;
            }
        }
        swap(spots[min_index],spots[i]);
    }
}

//helper function
void Sorting::insertionSort(vector<ScenicSpotVertex> &spots, int move) {
    for (int i = move; i <spots.size() ; ++i) {
        ScenicSpotVertex insertVertex = spots[i];//the one we want to move
        int j=i-move;//insertPosition
        while (j>=0 && spots[j].getWelcome()>insertVertex.getWelcome()){//if the previous one is still bigger, move.
            spots[j+move] = spots[j];
            j-=move;
        }
        spots[j+move] = insertVertex;
    }
}

/**
 * time: n^2
 * space: in-place -1
 * @param spots
 */
void Sorting::insertionSort(vector<ScenicSpotVertex> &spots) {
    insertionSort(spots,1);
}

/**
 * another version of insertionSort -- faster
 * time: n - small: n^2; n - big: n logn
 * space: in-place -1
 * @param spots
 */
void Sorting::shellSort(vector<ScenicSpotVertex> &spots) {
    if(spots.size() <= 1) return;

    int gap = spots.size() /2 ;
    while (gap>=1){
        insertionSort(spots,gap);
        gap /=2;
    }
}



void Sorting::merge(vector<ScenicSpotVertex> &spots, int start, int mid, int end) {
    //copy the part
    vector<ScenicSpotVertex> ans(end-start+1);
    int i=start,j=mid+1,k=0;
    //move to the vector
    while(i<=mid && j<=end){
        if(spots[i].getWelcome()<=spots[j].getWelcome()){
            ans[k++]=spots[i++];
        }
        else{
            ans[k++]=spots[j++];
        }
    }
    //move left part remaining
    while(i<=mid){
        ans[k++]=spots[i++];
    }
    //move
    while(j<=end){
        ans[k++]=spots[j++];
    }
    for(int ptr=0; ptr <= end - start; ptr++){
        spots[start + ptr]=ans[ptr];
    }




}

void Sorting::mergeSort(vector<ScenicSpotVertex> &spots, int start, int end) {
    if(start>=end) return;
    int mid = (start+end)/2;
    mergeSort(spots, start, mid);
    mergeSort(spots,mid+1, end);
    merge(spots, start, mid, end);
}


/**
 * time:nlogn -- n data; logn times
 * space - n
 * @param spots
 */
void Sorting::mergeSort(vector<ScenicSpotVertex> &spots) {
    mergeSort(spots, 0, spots.size()-1);
}


void Sorting::quickSort(vector<ScenicSpotVertex> &spots, int start, int end) {
    if(start>=end) return;

    //base to separate left and right
    ScenicSpotVertex base = spots[end];

    int left = start;
    int right = end-1;
    while (left<right){
        //find bigger one from the left
        while (left<right && spots[left].getWelcome()<base.getWelcome()){
            left++;
        }

        //find smaller one from right
        while (left<right && spots[right].getWelcome()>=base.getWelcome()){
            right--;
        }

        swap(spots[left],spots[right]);
    }

//    put base in the middle, sort
    if (spots[left].getWelcome() >= spots[end].getWelcome()) {
        std::swap(spots[left], spots[end]);
    } else {
        left++;
    }
    if (start < left - 1) {
        quickSort(spots, start, left - 1);
    }
    if (left + 1 < end) {
        quickSort(spots, left + 1, end);
    }
}

void Sorting::quickSort(vector<ScenicSpotVertex> &spots) {
    quickSort(spots,0,spots.size()-1);
}








