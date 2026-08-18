#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n, int m)
    {
        parent.resize(n * m);
        for (int i = 0; i < n * m; i++)
        {
            parent[i] = i;
        }

        rank.resize(n * m, 0);
    }

    int findUlimateParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findUlimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ult_u = findUlimateParent(u);
        int ult_v = findUlimateParent(v);

        if (ult_u == ult_v)
            return;

        if (rank[ult_u] > rank[ult_v])
        {
            parent[ult_v] = ult_u;
        }
        else if (rank[ult_u] < rank[ult_v])
        {
            parent[ult_u] = ult_v;
        }
        else
        {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

int noOfRows, noOfCols;
int getIndex(int r, int c)
{
    return r * noOfCols + c;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &queries)
{
    vector<int> res;
    noOfRows = n;
    noOfCols = m;

    DSU d(n, m);

    vector<vector<int>> grid(n, vector<int>(m, 0));
    int provinces = 0;

    for (auto q : queries)
    {
        int r = q[0];
        int c = q[1];

        if (grid[r][c] == 1)
        {
            res.push_back(provinces);
            continue;
        }

        grid[r][c] = 1;
        provinces++;

        int idx = getIndex(r, c);
        for (int i = 0; i < 4; i++)
        {
            int newr = r + dx[i];
            int newc = c + dy[i];
            int newIdx = getIndex(newr, newc);

            if (newr >= 0 && newc >= 0 && newr < n && newc < m && grid[newr][newc])
            {
                if (d.findUlimateParent(idx) != d.findUlimateParent(newIdx))
                {
                    d.unionByRank(idx, newIdx);
                    provinces--;
                }
            }
        }
        res.push_back(provinces);
    }
    return res;
}