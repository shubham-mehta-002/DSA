#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<int>> adj(V);

        // Build graph
        for (auto &v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<int> dist(V, INT_MAX);
        queue<pair<int, int>> q;

        dist[src] = 0;
        q.push({src, 0});

        while (!q.empty())
        {
            auto [node, currDist] = q.front();

            for (int n : adj[node])
            {
                if (currDist + 1 < dist[n])
                {
                    dist[n] = currDist + 1;
                    q.push({n, currDist + 1});
                }
            }
            q.pop();
        }

        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};