#ifndef CREATE_ADJACNECY_H
#define CREATE_ADJACNECY_H

#include <bits/stdc++.h>
using namespace std;

// Create adjacency list for a directed graph
template <typename T>
unordered_map<T, list<T>> createAdjListDirected(vector<vector<T>> &edges)
{
    unordered_map<T, list<T>> adjList;

    for (auto &edge : edges)
    {
        T u = edge[0];
        T v = edge[1];
        adjList[u].push_back(v);
    }
    return adjList;
}

// Create adjacency list for an undirected graph
template <typename T>
unordered_map<T, list<T>> createAdjListUndirected(vector<vector<T>> &edges)
{
    unordered_map<T, list<T>> adjList;

    for (auto &edge : edges)
    {
        T u = edge[0];
        T v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

#endif