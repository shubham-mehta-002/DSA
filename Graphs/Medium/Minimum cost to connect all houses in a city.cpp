#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &houses)
    {
        using pp = pair<int, int>;
        int n = houses.size();

        vector<vector<int>> costMatrix(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int dist = abs(houses[i][0] - houses[j][0]) + abs(houses[i][1] - houses[j][1]);
                costMatrix[i][j] = dist;
            }
        }

        int mstCost = 0;
        vector<int> vis(n, 0);
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (vis[node])
                continue;
            vis[node] = 1;
            mstCost += dist;

            for (int j = 0; j < n; j++)
            {
                if (!vis[j])
                {
                    pq.push({costMatrix[node][j], j});
                }
            }
        }
        return mstCost;
    }
};