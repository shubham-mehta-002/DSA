#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for (auto v : prerequisites)
        {
            int from = v[1];
            int to = v[0];

            adj[from].push_back(to);
            indegree[to]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (int neighbor : adj[top])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        for (int i : indegree)
        {
            if (i != 0)
                return false;
        }

        return true;
    }
};