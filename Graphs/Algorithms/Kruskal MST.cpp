// TC ->  O(N+E) + O(M log M) + O(2 * M * 4 * alpha) ~~~  O(N+E) + O(M log M) + O(M)
// SC -> O(N) + O(M) ~~~ O(N+M)
// where N -> number of vertices, E -> number of edges, M -> number of edges in the input graph,
// alpha -> inverse Ackermann function (very slow growing function, practically constant for all reasonable values of N)

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent;
    vector<int> rank;

public:
    // contructor
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0); // following 1-based indexing for ease
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]); // path compression
    }

    void unionByRank(int u, int v)
    {
        int parent_u = findUltimateParent(u);
        int parent_v = findUltimateParent(v);

        // if already in same component
        if (parent_u == parent_v)
        {
            return;
        }

        if (rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;
        }
        else
        { // same rank
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }
};

class Solution
{
public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        using pp = pair<int, pair<int, int>>;

        vector<pp> path;

        for (auto e : edges)
        {
            path.push_back({e[2], {e[0], e[1]}});
        }

        sort(path.begin(), path.end());

        int mstWt = 0;

        DisjointSet ds(V);

        for (auto p : path)
        {
            int wt = p.first;
            int u = p.second.first;
            int v = p.second.second;

            if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
            {
                mstWt += wt;
                ds.unionByRank(u, v);
            }
        }

        return mstWt;
    }
};