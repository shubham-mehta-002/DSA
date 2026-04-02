#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank;
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int p1 = findUltimateParent(u);
        int p2 = findUltimateParent(v);

        if (p1 == p2)
            return;

        if (rank[p1] < rank[p2])
        {
            parent[p1] = parent[p2];
        }
        else if (rank[p1] > rank[p2])
        {
            parent[p2] = parent[p1];
        }
        else
        {
            parent[p2] = parent[p1];
            rank[p1]++;
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);

        int extraWires = 0;
        for (auto c : connections)
        {
            int u = c[0];
            int v = c[1];

            if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
            {
                ds.unionByRank(u, v);
            }
            else
            {
                extraWires++;
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == ds.findUltimateParent(i))
            {
                provinces++;
            }
        }

        int actualWires = connections.size();
        int nonConnectedComponents = provinces - 1;

        if (extraWires >= nonConnectedComponents)
        {
            return nonConnectedComponents;
        }
        return -1;
    }
};