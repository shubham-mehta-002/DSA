#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void floydWarshall(int n, vector<vector<int>> &edges)
    {
        // floyd warshall
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // fill edges
        for (auto &e : edges)
        {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (dist[i][i] < 0)
                cout << "Negative cycle exists\n";
        }
    }
};