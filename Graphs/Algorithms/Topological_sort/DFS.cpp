#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node, vector<vector<int>> &adj, stack<int> &st, vector<int> &vis)
    {
        vis[node] = 1;

        for (int it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, st, vis);
            }
        }

        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        // create adjacency matrix
        for (auto v : edges)
        {
            int from = v[0];
            int to = v[1];

            adj[from].push_back(to);
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, st, vis);
            }
        }

        // extract from stack
        vector<int> topo;

        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};