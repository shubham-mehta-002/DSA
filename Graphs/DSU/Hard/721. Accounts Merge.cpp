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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);

        map<string, int> mpp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mpp.count(accounts[i][j]))
                {
                    // union
                    ds.unionByRank(mpp[accounts[i][j]], i);
                }
                else
                {
                    mpp[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> mergedMails(n);
        for (auto it : mpp)
        {
            int ultimatePairIndex = ds.findUltimateParent(it.second);
            mergedMails[ultimatePairIndex].push_back(it.first);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedMails[i].size() == 0)
                continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto s : mergedMails[i])
            {
                temp.push_back(s);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};