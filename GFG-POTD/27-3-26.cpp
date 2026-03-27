#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    int m;

public:
    int maxChocolate(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> next(m, vector<int>(m, 0));

        // base case
        for (int c1 = 0; c1 < m; c1++)
        {
            for (int c2 = 0; c2 < m; c2++)
            {
                if (c1 == c2)
                {
                    next[c1][c2] = grid[n - 1][c1];
                }
                else
                {
                    next[c1][c2] = grid[n - 1][c1] + grid[n - 1][c2];
                }
            }
        }

        for (int r = n - 2; r >= 0; r--)
        {
            vector<vector<int>> curr(m, vector<int>(m, 0));
            for (int c1 = m - 1; c1 >= 0; c1--)
            {
                for (int c2 = m - 1; c2 >= 0; c2--)
                {
                    // 3 cases
                    int maxTotal = 0;
                    for (int i = -1; i <= 1; i++)
                    {
                        for (int j = -1; j <= 1; j++)
                        {
                            int newC1 = c1 + i;
                            int newC2 = c2 + j;

                            if (newC1 >= 0 && newC2 >= 0 && newC1 < m && newC2 < m)
                            {
                                maxTotal = max(maxTotal, next[newC1][newC2]);
                            }
                        }
                    }

                    if (c1 == c2)
                    {
                        curr[c1][c2] = grid[r][c1] + maxTotal;
                    }
                    else
                    {
                        curr[c1][c2] = grid[r][c1] + grid[r][c2] + maxTotal;
                    }
                }
            }

            next = curr;
        }
        return next[0][m - 1];
    }
};