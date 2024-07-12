#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H
#include <bits/stdc++.h>
using namespace std;

// create adjacency list for a directed graph
template <typename T>
unordered_map<T, list<T>> createAdjListDirected(vector<vector<T>> &edges)
{
    unordered_map<T, list<T>> adjList;

    for (auto &edge : edges)
    {
        T u = edge[0];
        T v = edge[1];
        adj[u].push_back(v);
    }
    return adjList;
}

// create adjacency list for an udirected graph
template <typename T>
unordered_map<T, list<T>> createAdjListUndirected(vector<vector<T>> &edges)
{
    unordered_map<T, list<T>> adjList;

    for (auto &edge : edges)
    {
        T u = edge[0];
        T v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adjList;
}

// printing the adjacency list
template <typename T>
void printAdjList(unordered_map<T, list<T>> &adjList)
{
    for (auto &pair : adjList)
    {
        cout << "Node " << pair.first << " connects to ";
        for (auto &nbr : pair)
        {
            cout << nbr << " ";
        }
        cout << endl;
    }
}

// depth-first traversal of the graph
template <typename T>
vector<int> DFSUtil(T &node, unordered_map<T, bool> &visited, unordered_map<T, list<T>> adjList)
{
    vector<T> dfsOrder;
    visited[node] = true;
    dfsOrder.push_back(node);

    for (auto &nbr : adjList)
    {
        if (!visited[nbr])
        {
            DFSUtil(nbr, visited, adjList);
        }
    }
    return DFSUtil;
}

#endif