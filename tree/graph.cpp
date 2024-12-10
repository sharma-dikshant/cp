#include<iostream>
#include<vector>
using namespace std;

int main()
{
//! representantion of graph
//?1. using list of edges and nodes
// {{1,2}, {1,3}} here 1 is connected to 2 and 3
// but only using this we can't handle the isolate node
// so give the list of all nodes also

//?2. using adjacency matrix

//?3 using list of nodes and each node has a list of neighbours i.e. adjacency list

    int arr[][2] = {{1,2}, {1,3}, {2,3}, {3,4}}; //this is list of edges

    vector<vector<int>> adjList(5);

    for(int i=0; i<4; i++){
        adjList[arr[i][0]].push_back(arr[i][1]);
        adjList[arr[i][1]].push_back(arr[i][0]);

        //for adjacency matrix
        // adjMatrix[arr[i][0]][arr[i][1]] = 1;
        // adjMatrix[arr[i][1]][arr[i][0]] = 1;
    }

return 0;
}