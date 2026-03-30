#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pp;
class Solution
{
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<vector<pp>> adj(V);

        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(V, INT_MAX);

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty())
        {
            auto [currDist, node] = pq.top();

            for (auto [neighborNode, cost] : adj[node])
            {
                int newDist = cost + currDist;

                if (newDist < dist[neighborNode])
                {
                    dist[neighborNode] = newDist;
                    pq.push({newDist, neighborNode});
                }
            }

            pq.pop();
        }

        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
