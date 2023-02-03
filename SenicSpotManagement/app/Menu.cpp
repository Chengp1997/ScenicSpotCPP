//
// Created by 陈格平 on 2023/1/29.
//

#include "Menu.h"

[[noreturn]] void Menu::printMenu(ScenicSpotGraph graph){
    while (true){
        cout<<"\t******************************"<<endl;
        cout<<"\t    welcome to our system     "<<endl;
        cout<<"\t******************************"<<endl;
        cout<<"\t\t 1. print map               "<<endl;
        cout<<"\t\t 2. search spot information "<<endl;
        cout<<"\t\t 3. spot ranking            "<<endl;
        cout<<"\t\t 4. find shortest Path      "<<endl;
        cout<<"\t\t 5. travel with guide       "<<endl;
        cout<<"\t\t 6. spot lists              "<<endl;
        cout<<"\t\t 7. path lists              "<<endl;
        cout<<"\t\t 8. parking lot system      "<<endl;
        cout<<"\t\t 9. Exit                    "<<endl;
        cout<<"\t******************************"<<endl;
        cout<<"\t Enter your choice: "<<endl;
        int choice;
        cin>>choice;
        dealChoice(choice, graph);
    }

}

void Menu::dealChoice(int choice, ScenicSpotGraph graph) {
    switch (choice) {
        case 1://print map
            printMap(graph);
            break;
        case 2://search spot
            searchSpot(graph);
            break;
        case 3://spot ranking
            rankSpot(graph);
            break;
        case 4://find shortest path
            findShortestPath(graph);
            break;
        case 5://travel with guide
            spotGuidance(graph);
            break;
        case 6://spot lists
            printSpots(graph);
            break;
        case 7://path lists
            printPath(graph);
            break;
        case 8://parking lot system
            parkingRecord(graph);
            break;
        case 9://Exit
            exit();
            break;
        default:
            cout<<"wrong input, enter your choice again: "<<endl;
            break;
    }
}

void Menu::printMap(ScenicSpotGraph graph) {
    graph.printGraph();
}

void Menu::searchSpot(ScenicSpotGraph graph) {
    cout<< "Please input the name of the spot you want to search"<<endl;
    cout<<"(Enter E to exit)"<<endl;

    string name;
    cin>>name;

    if(name!="E"){
        ScenicSpotVertex* spotInfo = graph.searchSpot(name);
        if (spotInfo == nullptr)
            cout<<" No such spots, wrong input."<<endl;
        spotInfo->toString();
    }
}

void Menu::rankSpot(ScenicSpotGraph graph) {

}

void Menu::findShortestPath(ScenicSpotGraph graph) {

}

void Menu::spotGuidance(ScenicSpotGraph graph) {

}

void Menu::printSpots(ScenicSpotGraph graph) {

}

void Menu::printPath(ScenicSpotGraph graph) {

}

void Menu::parkingRecord(ScenicSpotGraph graph) {

}

void Menu::exit() {

}


