#include <bits/stdc++.h>
using namespace std;

class Solution
{
    typedef pair<int, int> p;

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<p>> adj(n + 1);
        for (auto t : times)
        {
            adj[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> cost(n + 1, INT_MAX);
        pq.push({0, k});
        cost[k] = 0;

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (cost[node] < dist)
                continue;

            for (auto [nextNode, nextNodeCost] : adj[node])
            {
                int newDist = nextNodeCost + dist;
                if (newDist < cost[nextNode])
                {
                    cost[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                }
            }
        }

        int maxTime = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (cost[i] == INT_MAX)
                return -1;
            maxTime = max(cost[i], maxTime);
        }
        return maxTime;
    }
};