#include <bits/stdc++.h>
using namespace std;

class Solution
{
    typedef pair<int, pair<int, int>> pp;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        priority_queue<pp, vector<pp>, greater<pp>> pq;

        pq.push({0, {0, 0}});
        cost[0][0] = 0;

        while (!pq.empty())
        {
            auto [effort, dim] = pq.top();
            auto [row, col] = dim;

            pq.pop();

            if (row == m - 1 && col == n - 1)
            {
                return effort;
            }

            if (effort > cost[row][col])
                continue;

            for (int i = 0; i < 4; i++)
            {
                int new_r = row + dx[i];
                int new_c = col + dy[i];

                if (new_r >= 0 && new_c >= 0 && new_r < m && new_c < n)
                {
                    int newEffort = max(effort, abs(heights[row][col] - heights[new_r][new_c]));

                    if (newEffort < cost[new_r][new_c])
                    {
                        cost[new_r][new_c] = newEffort;
                        pq.push({newEffort, {new_r, new_c}});
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};