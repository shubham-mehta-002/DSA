#include <bits/stdc++.h>
using namespace std;

class Solution
{
    typedef pair<int, int> pp;
    void trackPath(int node, vector<int> &parent, vector<int> &res)
    {
        if (node == -1)
            return;

        trackPath(parent[node], parent, res);
        res.push_back(node);
    }

public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // contruct adj matrix
        vector<vector<pp>> adj(n + 1);
        for (auto e : edges)
        {
            int node1 = e[0];
            int node2 = e[1];
            int wt = e[2];

            adj[node1].push_back({node2, wt});
            adj[node2].push_back({node1, wt});
        }

        // dist
        vector<int> dist(n + 1, INT_MAX);
        // parent
        vector<int> parent(n + 1, -1);

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        pq.push({0, 1});
        dist[1] = 0;

        while (!pq.empty())
        {
            int currentDist = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            if (dist[currentNode] < currentDist)
                continue;

            for (auto [neighbor, cost] : adj[currentNode])
            {
                int newDist = currentDist + cost;
                if (newDist < dist[neighbor])
                {
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                    parent[neighbor] = currentNode;
                }
            }
        }
        if (dist[n] == INT_MAX)
        {
            return {-1};
        }

        vector<int> res;
        res.push_back(dist[n]);
        trackPath(n, parent, res);

        return res;
    }
};