// TC - O(E.log E) + O(E.log E);
// SC - O(E) + O(V)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        using pp = pair<int, int>;
        // adj
        vector<vector<pp>> adj(V);
        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int sum = 0;
        vector<pp> mst;

        vector<int> vis(V, 0);
        priority_queue<pair<int, pp>, vector<pair<int, pp>>, greater<pair<int, pp>>> pq;

        pq.push({0, {0, -1}});

        while (!pq.empty())
        {
            auto top = pq.top();
            int cost = top.first;
            int node = top.second.first;
            int via = top.second.second;

            pq.pop();

            // if already visited
            if (vis[node] == 1)
                continue;

            vis[node] = 1;
            sum += cost;

            if (via != -1)
            {
                mst.push_back({via, node});
            }

            for (auto [neighbor, dist] : adj[node])
            {
                if (vis[neighbor] == 0)
                {
                    pq.push({dist, {neighbor, node}});
                }
            }
        }

        return sum;
    }
};