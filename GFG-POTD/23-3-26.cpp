#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int node, vector<int> &adj, vector<int> &path, vector<int> &visited, int step)
    {
        if (path[node] != -1)
        {
            return step - path[node];
        }

        if (visited[node] != -1)
        {
            return -1;
        }

        path[node] = step;
        int maxCycle = -1;

        if (adj[node] != -1)
        {
            maxCycle = max(maxCycle, dfs(adj[node], adj, path, visited, step + 1));
        }

        path[node] = -1;

        visited[node] = 1;

        return maxCycle;
    }

    int longestCycle(int V, vector<vector<int>> &edges)
    {
        vector<int> adj(V, -1);
        for (auto &e : edges)
        {
            adj[e[0]] = e[1];
        }

        vector<int> path(V, -1);
        vector<int> visited(V, -1);

        int maxCycle = -1;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == -1)
            {
                maxCycle = max(maxCycle, dfs(i, adj, path, visited, 1));
            }
        }

        return maxCycle;
    }
};
