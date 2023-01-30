cmake_minimum_required(VERSION 3.20)
project(SenicSpotManagement)

set(CMAKE_CXX_STANDARD 14)

add_executable(SenicSpotManagement app/main.cpp parking/Car.cpp parking/Car.h utils/dataStructure/Queue.h parking/ParkingLot.cpp parking/ParkingLot.h utils/graph/Vertex.cpp utils/graph/Vertex.h utils/graph/Edge.cpp utils/graph/Edge.h utils/common/Utils.cpp utils/common/Utils.h utils/dataStructure/Stack.h utils/dataStructure/LinkedList.h utils/dataStructure/HashMap.h scenicSpot/ScenicSpotVertex.cpp scenicSpot/ScenicSpotVertex.h utils/common/FileProcessor.cpp utils/common/FileProcessor.h scenicSpot/Graph.cpp scenicSpot/Graph.h scenicSpot/ScenicSpotEdge.cpp scenicSpot/ScenicSpotEdge.h app/Menu.cpp app/Menu.h)
