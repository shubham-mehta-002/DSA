#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {

        using pp = pair<int, int>; // {distance, node}

        vector<int> dist(V, INT_MAX);

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto [cost, node] = pq.top();
            pq.pop();

            // Skip stale entry
            if (cost > dist[node])
                continue;

            for (auto nbr : adj[node])
            {

                int nextNode = nbr[0];
                int weight = nbr[1];

                if (cost + weight < dist[nextNode])
                {

                    dist[nextNode] = cost + weight;

                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
    }
};