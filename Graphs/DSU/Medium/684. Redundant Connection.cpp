#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        rank.resize(n, 0);
    }

    int findUltimateParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ult_u = findUltimateParent(u);
        int ult_v = findUltimateParent(v);

        if (ult_u == ult_v)
        {
            return;
        }

        if (rank[ult_u] == rank[ult_v])
        {
            parent[ult_u] = ult_v;
            rank[ult_u]++;
        }
        else if (rank[ult_u] > rank[ult_v])
        {
            parent[ult_u] = ult_v;
        }
        else
        {
            parent[ult_v] = ult_u;
        }
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> res;
        DSU d(edges.size() + 1);

        for (auto e : edges)
        {
            if (d.findUltimateParent(e[0]) == d.findUltimateParent(e[1]))
            {
                return e;
            }
            else
            {
                d.unionByRank(e[0], e[1]);
            }
        }

        return res;
    }
};