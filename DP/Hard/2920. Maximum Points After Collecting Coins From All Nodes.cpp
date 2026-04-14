#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int node, vector<vector<int>> &adj, vector<int> &coins, int denominatorInPowerOfTwo, int k, int parent, vector<vector<int>> &mem)
    {
        if (node == coins.size())
        {
            return 0;
        }
        if (denominatorInPowerOfTwo >= 14)
            return 0;

        if (mem[node][denominatorInPowerOfTwo] != -1)
        {
            return mem[node][denominatorInPowerOfTwo];
        }

        int currVal = (coins[node] >> denominatorInPowerOfTwo); // divide by 2^denominatorInPowerOfTwo;

        // way 1
        int type1 = currVal - k;

        // way 2
        int type2 = currVal / 2;

        for (int nbr : adj[node])
        {
            if (nbr == parent)
                continue;
            type1 += find(nbr, adj, coins, denominatorInPowerOfTwo, k, node, mem);
            type2 += find(nbr, adj, coins, denominatorInPowerOfTwo + 1, k, node, mem);
        }

        return mem[node][denominatorInPowerOfTwo] = max(type1, type2);
    }
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
    {
        int n = coins.size();

        vector<vector<int>> adj(n);
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> mem(n, vector<int>(14, -1));

        return find(0, adj, coins, 0, k, -1, mem);
    }
};