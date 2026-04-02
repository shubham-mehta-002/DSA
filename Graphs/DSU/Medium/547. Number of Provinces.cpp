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
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        DisjointSet ds(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i == j)
                    continue;
                if (isConnected[i][j] == 1)
                {
                    ds.unionByRank(i, j);
                }
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == ds.findUltimateParent(i))
                provinces++;
        }

        return provinces;
    }
};