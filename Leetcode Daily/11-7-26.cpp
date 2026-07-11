#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> size;
    vector<int> edges;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }

        size.resize(n + 1, 1);
        edges.resize(n + 1, 0);
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ult_u = findUltimateParent(u);
        int ult_v = findUltimateParent(v);

        if (ult_u == ult_v)
        {
            return;
        }

        if (size[ult_u] >= size[ult_v])
        {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
            edges[ult_u] += edges[ult_v] + 1;
        }
        else
        {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
            edges[ult_v] += edges[ult_u] + 1;
        }
    }

    void addEdge(int node)
    {
        edges[node]++;
    }

    int getEdges(int node)
    {
        return edges[node];
    }

    int getSize(int node)
    {
        return size[node];
    }
};
class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        // vector<int>edgesCount;
        DSU d(n);

        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];

            if (d.findUltimateParent(u) == d.findUltimateParent(v))
            {
                d.addEdge(d.findUltimateParent(u));
            }
            else
            {
                d.unionBySize(u, v);
            }
        }

        int conn = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == d.findUltimateParent(i))
            {
                int cnt = d.getEdges(i);
                int count = ((d.getSize(i) - 1) * d.getSize(i)) / 2;

                if (cnt == count)
                {
                    conn++;
                }
            }
        }

        return conn;
    }
};