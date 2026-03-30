#include <bits/stdc++.h>
using namespace std;

class Solution
{
    typedef pair<int, pair<int, int>> pp;

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        // priority_queue<pp,vector<pp>, greater<pp>>pq;
        queue<pp> pq;

        pq.push({1, {0, 0}});
        cost[0][0] = 1;

        while (!pq.empty())
        {
            auto [dist, dim] = pq.front();
            auto [row, col] = dim;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (i == 0 && j == 0)
                        continue;
                    int new_r = row + i;
                    int new_c = col + j;

                    if (row == m - 1 && col == n - 1)
                        return dist;
                    if (dist > cost[row][col])
                        continue;

                    if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && grid[new_r][new_c] == 0 && cost[new_r][new_c] > dist + 1)
                    {
                        cost[new_r][new_c] = dist + 1;
                        pq.push({dist + 1, {new_r, new_c}});
                    }
                }
            }

            pq.pop();
        }

        return (cost[m - 1][n - 1] != INT_MAX ? cost[m - 1][n - 1] : -1);
    }
};