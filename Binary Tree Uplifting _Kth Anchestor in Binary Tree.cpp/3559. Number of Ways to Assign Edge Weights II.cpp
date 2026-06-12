#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &depth, int parent, int currDepth, vector<vector<int>> &ancestorTable)
    {
        depth[node] = currDepth;
        ancestorTable[node][0] = parent;

        for (int nbr : adj[node])
        {
            if (nbr == parent)
                continue;

            dfs(nbr, adj, depth, node, currDepth + 1, ancestorTable);
        }
    }

    void buildAncestorTable(vector<vector<int>> &ancestorTable, int nodes, int level)
    {

        for (int jump = 1; jump < level; jump++)
        {

            for (int node = 1; node <= nodes; node++)
            {

                int midAncestor = ancestorTable[node][jump - 1];

                if (midAncestor != -1)
                {
                    ancestorTable[node][jump] = ancestorTable[midAncestor][jump - 1];
                }
                else
                {
                    ancestorTable[node][jump] = -1;
                }
            }
        }
    }

    int getKthAncestor(vector<vector<int>> &ancestorTable, int node, int jumps, int level)
    {

        for (int bit = 0; bit < level; bit++)
        {

            if (jumps & (1 << bit))
            {

                if (node == -1)
                    break;

                node = ancestorTable[node][bit];
            }
        }

        return node;
    }

    int getLCA(vector<vector<int>> &ancestorTable, vector<int> &depth, int a, int b, int level)
    {

        if (depth[a] < depth[b])
        {
            swap(a, b);
        }

        a = getKthAncestor(ancestorTable, a, depth[a] - depth[b], level);

        if (a == b)
        {
            return a;
        }

        for (int jump = level - 1; jump >= 0; jump--)
        {

            if (ancestorTable[a][jump] != ancestorTable[b][jump])
            {
                a = ancestorTable[a][jump];
                b = ancestorTable[b][jump];
            }
        }

        return ancestorTable[a][0];
    }

    int fastExponential(long long a, long long power)
    {

        long long ans = 1;

        while (power > 0)
        {

            if (power & 1)
            {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            power >>= 1;
        }

        return ans;
    }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries)
    {

        vector<int> res;

        int nodes = edges.size() + 1;
        int level = log2(nodes) + 2;

        unordered_map<int, vector<int>> adj;
        vector<int> depth(nodes + 1, 0);
        vector<vector<int>> ancestorTable(nodes + 1, vector<int>(level, -1));

        for (auto &e : edges)
        {

            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, adj, depth, -1, 0, ancestorTable);

        buildAncestorTable(ancestorTable, nodes, level);

        for (auto &q : queries)
        {

            int a = q[0];
            int b = q[1];

            int lca = getLCA(ancestorTable, depth, a, b, level);

            long long distance = depth[a] + depth[b] - 2LL * depth[lca];

            if (distance == 0)
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(fastExponential(2, distance - 1));
            }
        }

        return res;
    }
};