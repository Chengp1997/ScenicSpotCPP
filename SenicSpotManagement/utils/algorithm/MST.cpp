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

bool MST::hamiltonCircuitDfs(int *path, bool *used, int step, ScenicSpotGraph graph) {
    if (step == graph.getSpots().size()){//already visited every spots
        int lastSpot = path[step-1];
        if (graph.adjacencyMatrix[lastSpot][0] > 0){ // can get back to 0 spot
            return true;
        }
        return false;
    }else{
        for (int i = 0; i < graph.getSpots().size(); ++i) {
            int lastSpot = path[step-1];
            if (!used[i] && graph.adjacencyMatrix[lastSpot][i] > 0){
                used[i] = true;
                path[step] = i;
                if (hamiltonCircuitDfs(path,used,step+1, graph))
                    return true;
                else{
                    used[i] = false;
                    path[step] = -1;
                }
            }
        }
    }
    return false;
}

int* MST::hamiltonCircuit(ScenicSpotGraph graph) {
    int size = graph.getSpots().size();
    bool used[size];
    int path[size];

    //initialization
    for (int i = 0; i < size; ++i) {
        used[i] = false;
        path[i] = -1;
    }
    //start from first spot
    used[0] = true;
    path[0] = 0;

    bool hasCircuit = hamiltonCircuitDfs(path,used,1,graph);

    if (hasCircuit){
        return path;
    }
    return nullptr;
}




