#include <bits/stdc++.h>
#include "createAdjacency.h"
#include "traversals.h"
#include "graphCycle.h"
#include "connected.h"
// #include "shortestPath.h"
using namespace std;

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}, {3, 3}};
    unordered_map<int, list<int>> adjListDirected = createAdjListDirected(edges);
    unordered_map<int, list<int>> adjListUndirected = createAdjListUndirected(edges);

    cout << "DFS Traversal starting from node 2 in directed graph:" << endl;
    vector<int> dfsOrder = DFS(adjListDirected, 2);
    for (int node : dfsOrder)
    {
        cout << node << " ";
    }
    cout << endl;

    cout << "BFS Traversal starting from node 2 in directed graph:" << endl;
    vector<int> bfsOrder = BFSUtil(2, adjListDirected);
    for (int node : bfsOrder)
    {
        cout << node << " ";
    }
    cout << endl;

    cout << "Checking if the undirected graph contains a cycle:" << endl;
    bool hasCycleUndirected = isCycleUndirected(adjListUndirected);
    if (hasCycleUndirected)
        cout << "The undirected graph contains a cycle" << endl;
    else
        cout << "The undirected graph does not contain a cycle" << endl;

    cout << "Checking if the directed graph contains a cycle:" << endl;
    bool hasCycleDirected = isCycleDirected(adjListDirected);
    if (hasCycleDirected)
        cout << "The directed graph contains a cycle" << endl;
    else
        cout << "The directed graph does not contain a cycle" << endl;

    return 0;
}
