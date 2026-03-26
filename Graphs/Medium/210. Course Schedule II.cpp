#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);

        vector<int> inDegree(numCourses, 0);
        vector<int> topo;

        for (auto p : prerequisites)
        {
            inDegree[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int top = q.front();
            topo.push_back(top);

            for (int a : adj[top])
            {
                inDegree[a]--;
                if (inDegree[a] == 0)
                {
                    q.push(a);
                }
            }
            q.pop();
        }

        return (topo.size() == numCourses ? topo : vector<int>{});
    }
};