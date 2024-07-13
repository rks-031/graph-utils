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
