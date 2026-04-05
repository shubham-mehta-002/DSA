#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int node, vector<int> &color, vector<vector<int>> &adj)
    {
        for (int adjNode : adj[node])
        {
            if (adjNode != node && color[adjNode] != -1 && color[adjNode] == color[node])
            {
                return false;
            }
        }
        return true;
    }
    bool find(int node, vector<vector<int>> &adj, vector<int> &color, int m, int n)
    {
        if (node == n)
            return true;
        for (int i = 0; i < m; i++)
        {
            color[node] = i;
            if (isSafe(node, color, adj))
            {
                if (find(node + 1, adj, color, m, n))
                {
                    return true;
                }
            }
            color[node] = -1;
        }

        return false;
    }

    bool graphColoring(int n, vector<vector<int>> &edges, int m)
    {
        vector<vector<int>> adj(n);
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, -1);
        return find(0, adj, color, m, n);
    }
};