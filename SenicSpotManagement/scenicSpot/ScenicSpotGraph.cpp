//
// Created by 陈格平 on 2023/1/26.
//

#include "ScenicSpotGraph.h"

//initial
void ScenicSpotGraph::initGraph() {
    //read from file
    vector<string> spotInfo = FileProcessor::readIn(VertexPath);
    vector<string> edgeInfo = FileProcessor::readIn(EdgesPath);
    //read in the spot and edge information
    initSpotsInfo(spotInfo);
    initEdgeInfo(edgeInfo);
}

void ScenicSpotGraph::initSpotsInfo(const vector<string>& spotInfo) {
    int index = 0;
    for (const string& info: spotInfo) {
        ScenicSpotVertex spot;
        vector<string> words = Utils::split(info);

        spot.setSpotName(words[0]);
        spot.setIntro(words[1]);
        spot.setWelcome(stoi(words[2]));
        spot.setRelaxPlace(!(words[3] == "NO"));
        spot.setRestRoom(!(words[4] == "NO"));
        spot.setIndex(index++);

        spotMap.insert(make_pair(spot.getSpotName(),spot));
        nodes.pushBack(spot);
    }
}

void ScenicSpotGraph::initEdgeInfo(const vector<string>& edgeInfo) {
    for(const string& edge: edgeInfo){
        vector<string> splitInfo =Utils::split(edge);
        ScenicSpotVertex start = *searchSpot(splitInfo[0]);
        ScenicSpotVertex des = *searchSpot(splitInfo[1]);
        int distance = stoi(splitInfo[2]);
        Edge* edgeSD = new Edge(start.getSpotName(),des.getSpotName(), distance);
        Edge* edgeDS = new Edge(des.getSpotName(),start.getSpotName(), distance);

        start.getEdges()->push_back(edgeSD);
        des.getEdges()->push_back(edgeDS);
    }
}

void ScenicSpotGraph::toAdjacencyMatrix() {
    //initialize adjacency matrix
    int size = nodes.size();
    adjacencyMatrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        adjacencyMatrix[i] = new int [size];
    }

    //not connected -- set to 32767
    //itself - 0
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            adjacencyMatrix[i][j] = INF;
            if (i == j) adjacencyMatrix[i][j] = 0;
        }
    }

    //set distance between nodes
    for (int i = 0; i < size; ++i) {//for all nodes
        Vertex vertex =  *nodes.get(i);
        for (auto & edge : *vertex.getEdges()) {
            int distance =  edge->getDistance();
            int pos = searchSpot(edge->getDestinationSpot())->getIndex();
            adjacencyMatrix[i][pos] = distance;
        }
    }

//    printMatrix();
}

ScenicSpotVertex* ScenicSpotGraph::searchSpot(const string& searchName) {
    auto iter = spotMap.find(searchName);
    if(iter == spotMap.end()) return nullptr;
    return &(iter->second);
}

LinkedList<ScenicSpotVertex> ScenicSpotGraph::getSpots() {
    return nodes;
}

void ScenicSpotGraph::printMatrix() {//print adjacency matrix
    cout<<"\t\t\t\t";
    for (int i = 0; i < nodes.size(); ++i) {
        ScenicSpotVertex vertex = *nodes.get(i);
        cout<< vertex.getSpotName() <<"\t";
    }
    cout<<endl;

    for(int i=0;i<nodes.size();i++){
        ScenicSpotVertex vertex = *nodes.get(i);
        cout<< vertex.getSpotName()<< " \t\t\t";
        for (int j = 0; j < nodes.size(); ++j) {
            if (adjacencyMatrix[i][j] == INF) cout<< "INF\t";
            else cout<<adjacencyMatrix[i][j]<<"\t";
        }
        cout<<endl;

    }
}

void ScenicSpotGraph::printEdges() {
    for (int i = 0; i < nodes.size(); ++i) {
        ScenicSpotVertex spot = *nodes.get(i);
        cout<<spot.getSpotName()<<"  ";
        for (auto edge : *spot.getEdges()) {
            cout<<"---"<<edge->getDistance()<<"--->"<<edge->getDestinationSpot()<<"\n\t\t";
        }
    }
}

void ScenicSpotGraph::printSpots() {
    cout<< "Here are the spots list of all scenic spots"<<endl;
    cout<< "There are "<< nodes.size()<<" spots in our park";
    cout<<"**************************"<<endl;
    for (int i = 0; i < nodes.size(); ++i) {
        if (i != 0) cout<<"-------------------------"<<endl;
        cout<<i+1<<". "<<nodes.get(i)->getSpotName()<<endl;
    }
    cout<<"**************************"<<endl;
}


