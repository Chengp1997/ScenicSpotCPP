//
// Created by 陈格平 on 2023/2/2.
//

#include "ShortestPath.h"

void ShortestPath::Floyd(Vertex start, Vertex end, ScenicSpotGraph graph) {
    int begin = start.getIndex();
    int des = end.getIndex();

    int size = graph.getSpots().size();
    int **path;
    int **distance;
    path = new int*[size];
    distance = new int*[size];
    for (int i = 0; i < size; ++i) {
        path[i] = new int[size];
        distance[i] = new int[size];
    }

    Floyd(path,distance,graph);

    vector<ScenicSpotVertex> roads;
    vector<int> totalDistance;
    int current = des;
    while (current != begin){
        roads.insert(roads.begin(),*graph.getSpots().get(current));
        totalDistance.insert(totalDistance.begin(), distance[current][begin]);
        current = path[current][begin];
    }

    roads.insert(roads.begin(), *graph.getSpots().get(current));
    totalDistance.insert(totalDistance.begin(), distance[current][begin]);

    //print out result
    printPath(roads,totalDistance);
}

/**
 *
 * @param path path[i][j] = k means - point i to point j will pass point k
 * @param distance distance[i][j] = sum means -min distance from i to j is sum
 * @param graph
 */
void ShortestPath::Floyd(int** path, int** distance, ScenicSpotGraph graph) {
    int size = graph.getSpots().size();

    //initialize
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            distance[i][j] = graph.adjacencyMatrix[i][j]; //initially, the weight of edge
            path[i][j] = j; 
        }
    }
    
    //calculate
    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j <size ; ++j) {
                //calculate distance and check
                int temp = (distance[i][k] == INF||distance[k][j]==INF)?
                        INF:(distance[i][k]+distance[k][j]);
                if (temp<distance[i][j]){
                    distance[i][j] = temp;//distance should be smaller
                    path[i][j] = path[i][k]; // i j will pass k
                }
            }
        }
    }

}


/**
 *
 * @param start index of the start vertex
 * @param shortestPath previous vertex of current node
 * @param distance min distance from start to node i
 * @param graph current graph
 * @return
 */
void ShortestPath::Dijkstra(int start, int shortestPath[], int distance[], ScenicSpotGraph graph) {
    int size = graph.getSpots().size();
    int visited[size]; // have visited or not

    //initialize
    for (int i = 0; i < size; ++i) {
        visited[i] = 0;  //0-not visited; 1-visited
        distance[i] = graph.adjacencyMatrix[start][i];
        shortestPath[i] = start;
    }

    //vertex itself
    visited[start] = 1;
    distance[start] = 0;
    shortestPath[start] = -1;

    int min;
    int currentVertex;
    //search for other vertexes
    for (int i = 1; i < size; ++i) {
        min = INF;
        //find current min path from start to currentVertex
        for (int j = 0; j < size; ++j) {
            if (visited[j] == 0 && distance[j]<min){
                min = distance[j];
                currentVertex = j;
            }
        }
        visited[currentVertex] = 1;

        //already find it, update distance/shortestPath
        for (int j = 0; j < size; ++j) {
            //update every distance from start
            int temp = (graph.adjacencyMatrix[currentVertex][j]== INF ?
                    INF : graph.adjacencyMatrix[currentVertex][j]+min);
            //not visited, and shorter
            if (visited[j] == 0 && (temp<distance[j])){
                distance[j] = temp;
                shortestPath[j] = currentVertex;
            }
        }
    }
}

void ShortestPath::Dijkstra(Vertex start, Vertex end, ScenicSpotGraph graph) {
    int startIndex = start.getIndex();
    int endIndex = end.getIndex();
    int size = graph.getSpots().size();
    int prev[size];
    int distance[size];

    Dijkstra(startIndex,prev,distance,graph);

    int current = endIndex;
    vector<ScenicSpotVertex> roads;
    vector<int> totalDistance;
    while (prev[current]!=-1){
        roads.insert(roads.begin(),*graph.getSpots().get(current));
        totalDistance.insert(totalDistance.begin(), distance[current]);
        current = prev[current];
    }
    roads.insert(roads.begin(), *graph.getSpots().get(current));
    totalDistance.insert(totalDistance.begin(), distance[current]);

    //print out result
    printPath(roads,totalDistance);
}

void ShortestPath::printPath(vector<ScenicSpotVertex> roads, vector<int> distance) {
    cout<< "shortest path from "<<
        roads.at(0).getSpotName()<<" to "<<
        roads.at(roads.size()-1).getSpotName()<<":  "<<endl;
    for (int i=0; i<roads.size();i++) {
        if (i != 0) {
            cout<<"-----total distance: "<<distance[i]<<"---->";
        }
        cout<< roads[i].getSpotName();
    }
    cout<<endl;
}

void ShortestPath::findShortestRoad(const string& start, const string& des, ScenicSpotGraph graph) {
    if (graph.searchSpot(start)== nullptr||graph.searchSpot(des) == nullptr){
        cout<<"\t\t wrong input, enter again";
        return;
    }
    Vertex startSpot = *graph.searchSpot(start);
    Vertex endSpot = *graph.searchSpot(des);

    cout<<"Dijkstra algorithm: "<<endl;
    Dijkstra(startSpot, endSpot, graph);
    cout<<"Floyd algorithm: "<<endl;
    Floyd(startSpot,endSpot, graph);
}



