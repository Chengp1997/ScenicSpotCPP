cmake_minimum_required(VERSION 3.20)
project(SenicSpotManagement)

set(CMAKE_CXX_STANDARD 14)

add_executable(SenicSpotManagement main.cpp dataStructure/DoubleLinkedList.cpp dataStructure/DoubleLinkedList.h dataStructure/Node.cpp dataStructure/Node.h parking/Car.cpp parking/Car.h dataStructure/Queue.cpp dataStructure/Queue.h dataStructure/LinkedListNode.cpp dataStructure/LinkedListNode.h parking/ParkingLot.cpp parking/ParkingLot.h model/Vertex.cpp model/Vertex.h model/Edge.cpp model/Edge.h model/Graph.cpp model/Graph.h)
