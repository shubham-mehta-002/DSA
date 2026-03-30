#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        using pp = pair<long long, int>;
        vector<vector<pp>> adj(n);

        for (auto r : roads)
        {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> cost(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, 0});
        cost[0] = 0;
        ways[0] = 1;

        while (!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();

            for (auto [nbr, c] : adj[node])
            {
                if (cost[nbr] > dist + c)
                {
                    cost[nbr] = dist + c;
                    ways[nbr] = ways[node];
                    pq.push({cost[nbr], nbr});
                }
                else if (cost[nbr] == dist + c)
                {
                    ways[nbr] = (ways[nbr] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};