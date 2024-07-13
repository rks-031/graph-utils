#ifndef TRAVERSALS_H
#define TRAVERSALS_H

#include <bits/stdc++.h>
using namespace std;

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
