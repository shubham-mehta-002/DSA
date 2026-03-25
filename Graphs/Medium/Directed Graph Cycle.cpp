#include <bits/stdc++.h>
using namespace std;
class Solution

{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> inDegree(V, 0);

        // create adjacency matrix
        for (auto v : edges)
        {
            int from = v[0];
            int to = v[1];

            adj[from].push_back(to);
            inDegree[to]++;
        }

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();

            for (int it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
            q.pop();
        }

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] != 0)
            {
                return true;
            }
        }

        return false;
    }
};