#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        long long totalSum;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                totalSum += grid[i][j];
            }
        }

        // horizontal cut
        long long hSum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                hSum += grid[i][j];
            }

            if (hSum * 2 == totalSum)
            {
                return true;
            }
        }

        // vertical cut
        long long vSum = 0;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                vSum += grid[i][j];
            }

            if (vSum * 2 == totalSum)
            {
                return true;
            }
        }

        return false;
    }
};