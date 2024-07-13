#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <bits/stdc++.h>
using namespace std;

// Shortest path using Dijkstra's algorithm
template <typename T>
unordered_map<T, T> dijkstra(unordered_map<T, list<pair<T, int>>> &adjList, T startNode)
{
    unordered_map<T, int> distances;
    unordered_map<T, T> previous;
    set<pair<int, T>> pq; // Priority queue to store (distance, node)

    for (const auto &pair : adjList)
    {
        distances[pair.first] = INT_MAX;
        previous[pair.first] = T();
    }

    distances[startNode] = 0;
    pq.insert({0, startNode});

    while (!pq.empty())
    {
        T node = pq.begin()->second;
        pq.erase(pq.begin());

        for (const auto &neighbor : adjList.at(node))
        {
            T neighborNode = neighbor.first;
            int weight = neighbor.second;

            int newDist = distances[node] + weight;
            if (newDist < distances[neighborNode])
            {
                pq.erase({distances[neighborNode], neighborNode});
                distances[neighborNode] = newDist;
                previous[neighborNode] = node;
                pq.insert({newDist, neighborNode});
            }
        }
    }

    return previous;
}

#endif // SHORTEST_PATH_H
