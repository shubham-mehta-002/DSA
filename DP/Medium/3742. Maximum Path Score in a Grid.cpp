#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, INT_MIN)));

        // base case
        for (int rem = 0; rem <= k; rem++)
        {
            dp[n - 1][m - 1][rem] = 0;
        }

        for (int row = n - 1; row >= 0; row--)
        {
            for (int col = m - 1; col >= 0; col--)
            {
                for (int rem = 0; rem <= k; rem++)
                {
                    if (row == n - 1 && col == m - 1)
                        continue;
                    int maxScore = INT_MIN;

                    // right
                    if (row < n && row >= 0 && col >= 0 && col + 1 < m)
                    {
                        int cost = (grid[row][col + 1] == 0 ? 0 : 1);
                        int add = grid[row][col + 1];

                        if (rem - cost >= 0)
                        {
                            maxScore = max(
                                maxScore,
                                add + dp[row][col + 1][rem - cost]);
                        }
                    }

                    // bottom
                    if (row + 1 < n && row >= 0 && col >= 0 && col < m)
                    {
                        int cost = (grid[row + 1][col] == 0 ? 0 : 1);
                        int add = grid[row + 1][col];
                        if (rem - cost >= 0)
                        {
                            maxScore = max(
                                maxScore,
                                add + dp[row + 1][col][rem - cost]);
                        }
                    }

                    dp[row][col][rem] = maxScore;
                }
            }
        }

        int ans = dp[0][0][k];

        return (ans < -1e5 ? -1 : ans);
    }
};