#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

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

// Print the adjacency list
template <typename T>
void printAdjList(unordered_map<T, list<T>> &adjList)
{
    for (auto &pair : adjList)
    {
        cout << "Node " << pair.first << " connects to ";
        for (auto &nbr : pair.second)
        {
            cout << nbr << " ";
        }
        cout << endl;
    }
}

// Depth-first traversal of the graph
template <typename T>
void DFSUtil(T node, unordered_map<T, bool> &visited, unordered_map<T, list<T>> &adjList, vector<T> &dfsOrder)
{
    visited[node] = true;
    dfsOrder.push_back(node);

    for (auto &nbr : adjList[node])
    {
        if (!visited[nbr])
        {
            DFSUtil(nbr, visited, adjList, dfsOrder);
        }
    }
}

template <typename T>
vector<T> DFS(unordered_map<T, list<T>> &adjList, T startNode)
{
    unordered_map<T, bool> visited;
    for (auto &pair : adjList)
    {
        visited[pair.first] = false;
    }

    vector<T> dfsOrder;
    DFSUtil(startNode, visited, adjList, dfsOrder);
    return dfsOrder;
}

// Breadth-first traversal of the graph
template <typename T>
vector<T> BFSUtil(T startNode, unordered_map<T, list<T>> &adjList)
{
    vector<T> bfsOrder;
    unordered_map<T, bool> visited;
    for (auto &pair : adjList)
    {
        visited[pair.first] = false;
    }

    queue<T> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        T node = q.front();
        q.pop();
        bfsOrder.push_back(node);

        for (auto &nbr : adjList[node])
        {
            if (!visited[nbr])
            {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
    return bfsOrder;
}

#endif
