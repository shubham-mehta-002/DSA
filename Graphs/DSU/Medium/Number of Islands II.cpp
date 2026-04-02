#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> rank;
    vector<int> parent;

    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, -1);
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

int getIndex(int r, int c, int totalCols)
{
    return (r * totalCols) + c;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> numberOfIslandII(int n, int m, vector<vector<int>> &queries, int q)
{
    DisjointSet ds(n * m);
    vector<int> res;
    int islands = 0;
    for (auto q : queries)
    {
        int r = q[0];
        int c = q[1];

        int index = getIndex(r, c, m);
        // already processed;
        if (ds.parent[index] != -1)
        {
            res.push_back(islands);
            continue;
        };

        if (ds.parent[index] == -1)
            islands++;
        ds.parent[index] = index;

        for (int i = 0; i < 4; i++)
        {
            int new_r = r + dx[i];
            int new_c = c + dy[i];

            int newIndex = getIndex(new_r, new_c, m);
            if (new_r >= 0 && new_c >= 0 && new_r < n && new_c < m && ds.parent[newIndex] != -1)
            {
                if (ds.findUltimateParent(index) != ds.findUltimateParent(newIndex))
                {
                    ds.unionByRank(index, newIndex);
                    islands--;
                }
            }
        }

        res.push_back(islands);
    }

    return res;
}
