#ifndef CYCLE_DETECTION_H
#define CYCLE_DETECTION_H

#include <bits/stdc++.h>
using namespace std;

// cycle detection in an undirected graph
template <typename T>
bool dfsUnorderedCycle(T node, vector<bool> &vis, unordered_map<T, list<T>> adjList, T parent)
{
    vis[node] = true;

    for (auto &nbr : adjList[node])
    {
        if (!vis[nbr])
        {
            if (dfsUnorderedCycle(nbr, vis, adjList, node))
                return true;
        }
        else if (nbr != parent)
            return true;
    }
    return false;
}

template <typename T>
bool isCycleUndirected(unordered_map<T, list<T>> adjList)
{
    T V = adjList.size();
    vector<bool> vis(V, false);
    for (T i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfsUnorderedCycle(i, vis, adjList, -1))
                return true;
        }
    }
    return true;
}

// cycle detection in a directed graph
template <typename T>
bool isCycleDirected(unordered_map<T, list<T>> adjList)
{
    T V = adjList.size();
    vector<T> indegree(V);

    for (T i = 0; i < V; i++)
    {
        for (auto nbr : adjList[i])
        {
            indegree[nbr]++;
        }
    }

    stack<T> s;

    for (T i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            s.push(i);
    }

    T count = 0;

    while (!s.empty())
    {
        T top = s.top();
        s.pop();

        count++;

        for (auto &nbr : adjList[top])
        {
            indegree[nbr]--;

            if (indegree[nbr] == 0)
                s.push(nbr);
        }
    }
    return count != V;
}

#endif