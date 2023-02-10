//
// Created by 陈格平 on 2023/1/29.
//

#include "Menu.h"

#include <utility>
#include "../utils/algorithm/ShortestPath.h"

[[noreturn]] void Menu::printMenu(){
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
        dealChoice(choice);
    }

}

void Menu::dealChoice(int choice) {
    switch (choice) {
        case 1://print map
            printMap();
            break;
        case 2://search spot
            searchSpot();
            break;
        case 3://spot ranking
            rankSpot();
            break;
        case 4://find shortest path
            findShortestPath();
            break;
        case 5://travel with guide
            spotGuidance();
            break;
        case 6://spot lists
            printSpots();
            break;
        case 7://path lists
            printPath();
            break;
        case 8://parking lot system
            printParkingMenu();
            break;
        case 9://Exit
            exit();
            break;
        default:
            cout<<"wrong input, enter your choice again: "<<endl;
            break;
    }
}

void Menu::printMap() {
    graph.printMatrix();
}

void Menu::searchSpot() {
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

void Menu::rankSpot() {
    cout<<"Show popular ranking here"<<endl;
    vector<ScenicSpotVertex> sorted;
    LinkedList<ScenicSpotVertex> spots = graph.getSpots();
    sorted.reserve(spots.size());
    for(int i=0;i<spots.size();i++){
        sorted.push_back(*spots.get(i));
    }
    Sorting::quickSort(sorted);
}

void Menu::findShortestPath() {
    cout<< "\t\t*****Please input your start spot:  ";
    string begin;
    cin>> begin;
    cout<<"\t\t******Please input your end spot:   ";
    string end;
    cin>> end;

    ShortestPath::findShortestRoad(begin, end,std::move(graph));
}

void Menu::spotGuidance() {
    string start;
    string end;
    cout<<"\t\tWe can give you a guidance of the trip"<<endl;
    cout<<"\t\tPlease input your current position"<<endl;
    cin>>start;
    int* path = MST::hamiltonCircuit(graph);
    if (path == nullptr){
        cout<<"no hamilton circuit, here's our guidance for you to travel through all spots"<<endl;
    } else{
        for (int i = 0; i < graph.getSpots().size(); ++i) {
            cout<<graph.getSpots().get(path[(i+ stoi(start))%graph.getSpots().size()]);
            cout<<" --->  ";
        }
        cout<<endl;
    }
}

void Menu::printSpots() {
    graph.printSpots();

    cout<<"print number to see detail or print E to exit:";
    string number;
    cin>>number;
    if (number == "E")return;
    if (stoi(number) > graph.getSpots().size()){
        cout<<"wrong enter"<<endl;
        return;
    }
    graph.getSpots().get(stoi(number) - 1)->toString();
}

void Menu::printPath() {
    graph.printEdges();
}

void Menu::exit() {
    cout<<"Thank you for using our Scenic spot management system! Goodbye"<<endl;
    ::exit(0);
}

void Menu::printParkingMenu() {
    while (true){
        cout<<"1. Park"<<endl;
        cout<<"2. Leave "<<endl;
        cout<<"3. check current parking lot status"<<endl;
        cout<<"4. exit"<<endl;
        int choice;
        cin>>choice;
        if (choice == 1){
            cout<<"Please input your car plate"<<endl;
            string carPlate;
            cin>>carPlate;
            parkingLot.park(carPlate);
        } else if (choice == 2){
            cout<<"Please input your car plate"<<endl;
            string carPlate;
            cin>>carPlate;
            parkingLot.leave(carPlate);
        } else if (choice == 3){
            parkingLot.showParkingLot();
        } else{
            cout<<"Thank you for using our parking system"<<endl;
            break;
        }
    }
}




