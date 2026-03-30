#include <bits/stdc++.h>
using namespace std;

class Solution
{
    typedef pair<int, int> pp;

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pp>> adj(n);

        for (auto f : flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> cost(n, INT_MAX);

        queue<pair<int, pp>> pq; // {k,{cost,node}}

        pq.push({-1, {0, src}});
        cost[src] = 0;

        while (!pq.empty())
        {
            auto top = pq.front();
            int stops = top.first;
            int currCost = top.second.first;
            int node = top.second.second;

            // if(node == dst && stops <= k){
            //     return currCost;
            // }
            pq.pop();

            if (k < stops + 1)
            {
                continue;
            }

            for (auto [ngh, dist] : adj[node])
            {
                if (cost[ngh] > currCost + dist && stops < k)
                {
                    cost[ngh] = currCost + dist;
                    pq.push({stops + 1, {cost[ngh], ngh}});
                }
            }
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};