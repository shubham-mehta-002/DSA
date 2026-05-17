#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, m;

public:
    int minCost(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        // vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(m,vector<bool>(1024,false)));
        vector<vector<bool>> prev(m, vector<bool>(1024, false));

        // base case
        prev[0][grid[0][0]] = true;

        for (int i = 0; i < n; i++)
        {
            vector<vector<bool>> curr(m, vector<bool>(1024, false));

            if (i == 0)
                curr[0][grid[0][0]] = true;

            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                for (int xorr = 0; xorr < 1024; xorr++)
                {

                    // up
                    if (i - 1 >= 0 && prev[j][xorr])
                        curr[j][xorr ^ grid[i][j]] = 1;

                    // left
                    if (j - 1 >= 0 && curr[j - 1][xorr])
                        curr[j][xorr ^ grid[i][j]] = 1;
                }
            }
            prev = curr;
        }

        // find minimum XOR at destination
        for (int x = 0; x < 1024; x++)
        {
            if (prev[m - 1][x])
                return x;
        }

        return -1;
    }
};