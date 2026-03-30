// TC -> O(V . E)
// SC -> O(V)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // relax edges V-1 times
        for (int i = 0; i < V - 1; i++)
        {
            for (auto e : edges)
            {
                int from = e[0];
                int to = e[1];
                int wt = e[2];

                if (dist[from] != INT_MAX && dist[from] + wt < dist[to])
                {
                    dist[to] = dist[from] + wt;
                }
            }
        }

        // negative cycle check
        for (auto e : edges)
        {
            int from = e[0];
            int to = e[1];
            int wt = e[2];

            if (dist[from] != INT_MAX && dist[from] + wt < dist[to])
            {
                return {-1};
            }
        }

        return dist;
    }
};