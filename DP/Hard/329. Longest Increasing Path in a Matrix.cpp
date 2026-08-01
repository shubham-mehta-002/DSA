#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        int maxx = 0;

        for (int row = n - 1; row >= 0; row--)
        {
            for (int col = m - 1; col >= 0; col--)
            {
                int ans = 1;
                for (int i = 0; i < 4; i++)
                {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];

                    if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && matrix[newRow][newCol] > matrix[row][col])
                    {
                        ans = max(ans, 1 + dp[newRow][newCol]);
                    }

                    dp[row][col] = ans;

                    maxx = max(maxx, dp[row][col]);
                }
            }
        }

        return maxx;
    }
};