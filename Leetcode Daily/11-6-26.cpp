#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static constexpr int MOD = 1e9 + 7;

    int fastExponentail(long long a, long long b)
    {
        if (b == 0)
            return 1;

        long long half = fastExponentail(a, b / 2);
        long long res = (half * half) % MOD;

        if (b & 1)
        {
            res = (res * a) % MOD;
        }

        return (int)res;
    }

public:
    int findDepth(unordered_map<int, vector<int>> &adj)
    {
        queue<pair<int, int>> q; // {node, parent}
        q.push({1, -1});

        int depth = 0;

        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                auto [node, parent] = q.front();
                q.pop();

                for (int nbr : adj[node])
                {
                    if (nbr == parent)
                        continue;
                    q.push({nbr, node});
                }
            }

            if (!q.empty())
                depth++;
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;

        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxDepth = findDepth(adj);

        if (maxDepth == 0)
            return 1;

        return fastExponentail(2, maxDepth - 1);
    }
};