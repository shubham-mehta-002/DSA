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
            parent[ult_v] = ult_u;
        }
        else if (rank[ult_u] > rank[ult_v])
        {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
        else
        {
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }
};
class Solution
{
public:
    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
    {
        DSU d(n);
        vector<bool> ans;

        for (auto r : requests)
        {
            int p1 = d.findUltimateParent(r[0]);
            int p2 = d.findUltimateParent(r[1]);

            if (p1 == p2)
            {
                ans.push_back(true);
                continue;
            }

            bool isValid = true;
            for (auto res : restrictions)
            {
                int res_p1 = d.findUltimateParent(res[0]);
                int res_p2 = d.findUltimateParent(res[1]);

                if (res_p1 == p1 && res_p2 == p2)
                {
                    // ans.push_back(false);
                    isValid = false;
                    break;
                }
                if (res_p1 == p2 && res_p2 == p1)
                {
                    // ans.push_back(false);
                    isValid = false;
                    break;
                }
            }

            if (isValid)
            {
                d.unionByRank(r[0], r[1]);
            }

            ans.push_back(isValid);
        }

        return ans;
    }
};