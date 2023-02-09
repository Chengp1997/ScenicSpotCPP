//
// Created by 陈格平 on 2023/2/8.
//

#include "MST.h"

void MST::generateGuidance(const std::string& start, ScenicSpotGraph graph) {
    int startIndex = graph.searchSpot(start)->getIndex();
    cout<<"using Prim algorithm: "<<endl;
    prim(startIndex,graph);
}

void MST::prim(int start, ScenicSpotGraph graph) {
    int size = graph.getSpots().size();
    vector<ScenicSpotVertex> tree; // to store the minimum spanning tree
    int weights[size]; // to store the weights of the tree;
    int index = 0;

    //initialization
    tree.push_back(*graph.getSpots().get(start)); //first node should be start
    for (int i = 0; i < size; ++i) {//weights should be start to i's weight
        weights[i] = graph.adjacencyMatrix[start][i];
    }
    weights[start] = 0;//weights to itself should be 0;

    for (int i = 0; i < size; ++i) {
        if (i == start){
            continue;// do not need to process the start node
        }

        int current=0;
        int min = INF;
        //find the node with minimum weights
        for (int j = 0; j < size; ++j) {
            //weights == 0 - means already processed
            if (weights[j] != 0 && weights[j]<min){
                min = weights[j];
                current = j;
            }
        }

        //set the node
        tree.push_back(*graph.getSpots().get(current));
        weights[current] = 0; // set to 0 - already find it

        //update weights
        for (int j = 0; j < size; ++j) {
            if (weights[j]!=0 && graph.adjacencyMatrix[current][j]<weights[j]){
                weights[j] = graph.adjacencyMatrix[current][j];
            }
        }
    }

    vector<int> sum;
    for (int i = 1; i < size; ++i) {
        int min = INF;
        for (int j = 0; j < i; ++j) {
            //find the min distance from i to j
            int current = graph.adjacencyMatrix[tree[j].getIndex()][tree[i].getIndex()];
            if (current<min){
                min = current;
            }
        }
        sum.push_back(min);
    }

    printPath(tree,sum);
}

void MST::printPath(vector<ScenicSpotVertex> path,vector<int> sum) {
    cout<<"Guidance from "<<path[0].getSpotName()<<endl;
    int count = 0;
    for (int i = 0; i <path.size(); ++i) {
        cout<< path[i].getSpotName();
        if (i!=path.size()-1) cout<<"--"<<sum[i]<<"-->";
        count+=sum[i];
    }
    cout<<"\ntotal cost: "<<count<<endl;
}

void MST::kruskal(ScenicSpotGraph graph) {

}


