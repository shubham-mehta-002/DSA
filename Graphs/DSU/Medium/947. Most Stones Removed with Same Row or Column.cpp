#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        size.resize(n, 1);
    }

    int findUltimateParent(int node)
    {
        if (parent[node] == node)
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
        }
        else
        {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
    }

    int getSize(int index)
    {
        return size[index];
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0, maxCol = 0;

        for (auto s : stones)
        {
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }
        maxRow++;
        maxCol++;

        DSU d(maxRow + maxCol);

        for (auto s : stones)
        {
            int r = s[0];
            int c = s[1];

            d.unionBySize(r, c + maxRow);
        }

        int components = 0;
        for (int i = 0; i < maxRow + maxCol; i++)
        {
            if (d.getSize(i) > 1 && d.findUltimateParent(i) == i)
            {
                components++;
            }
        }

        return stones.size() - components;
    }
};