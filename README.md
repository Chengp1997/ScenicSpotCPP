# ScenicSpotCPP

This is a simple data structure project of scenic spot management system. 

It's written in C++, I re-organized this project, changed it from Java to C++. 

<img src="images/image-20230211210432044.png" alt="image-20230211210432044" style="zoom:50%;" />

This Project contains two main subsystem: scenic spot management system and scenic spot parking lot management system. 



## Scenic Spot Management System

- Scenic spot management system: This is a graph project. 
  - Users can see routes between spots(adjacency matrix)
    - ![image-20230211211124095](images/image-20230211211124095.png)
  - search spot information
    - <img src="images/image-20230211211201058.png" alt="image-20230211211201058" style="zoom:50%;" />
  - see the ranking of the popularity between spots
    - <img src="images/image-20230211211224454.png" alt="image-20230211211224454" style="zoom:50%;" />
  - find shortest path between two spots
    - <img src="images/image-20230211211315650.png" alt="image-20230211211315650" style="zoom:50%;" />
  - see the guidance path.
    - <img src="images/image-20230211211347947.png" alt="image-20230211211347947" style="zoom:50%;" />
  - see the full spot list
    - <img src="images/image-20230211211438110.png" alt="image-20230211211438110" style="zoom:50%;" />
  - see the path list
    - <img src="images/image-20230211212041362.png" alt="image-20230211212041362" style="zoom:50%;" />



This is the class diagram of the graph management system.

- Sorting algorithm includes: bubble sort, insertion sort, selection sort, insertion sort, merge sort, quicksort, shell sort
- Shortest path algorithm includes: Dijkstra, Floyd
- MST algorithm includes: Prim(implemented but not used here, find a better one to implement the guidance map), DFS to find hamilton circuit

![IMG_0689](images/IMG_0689.PNG)





## Parking lot System

<img src="images/image-20230211212531930.png" alt="image-20230211212531930" style="zoom:50%;" />

parking lot system includes

- park the car

  - If the parking lot is not full

    <img src="images/image-20230211212604366.png" alt="image-20230211212604366" style="zoom:50%;" />

  - If the parking lot is full, all cars will go to the waiting line

    <img src="images/image-20230211213740412.png" alt="image-20230211213740412" style="zoom:50%;" />

- leave the parking lot
  - <img src="images/image-20230211213841996.png" alt="image-20230211213841996" style="zoom:50%;" />
- show current status of the parking lot
  - <img src="images/image-20230211213901330.png" alt="image-20230211213901330" style="zoom:50%;" />



This is the class digram of the parking lot system.

The parking lot has 3 data structure 

- parking space: this is the place where car park.
- buffer stack: This is the buffer when parking lot is full,  it will be used to store the car that should not be out of the parking lot.
- waiting line: when parking lot is full, car will be stay in line
- record: used to find car more quickly.

The car has three status: INLOT, OUTLOT, WAITING. Use the enum class to better manipulate the car. 

![IMG_0690](images/IMG_0690.PNG)