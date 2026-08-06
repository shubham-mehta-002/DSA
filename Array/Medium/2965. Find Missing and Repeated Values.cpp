#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int size = grid.size();
        int n = grid.size() * grid.size();

        long long requiredSum = 1LL * n * (n + 1) / 2;
        long long requiredSqSum = 1LL * n * (n + 1) * (2 * n + 1) / 6;

        long long actualSum = 0;
        long long actualSqSum = 0;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                actualSum += 1LL * grid[i][j];
                actualSqSum += 1LL * grid[i][j] * grid[i][j];
            }
        }

        long long x_minus_y = requiredSum - actualSum;
        long long x_sq_minus_y_sq = requiredSqSum - actualSqSum;

        long long x_plus_y = x_sq_minus_y_sq / x_minus_y;

        int x = (x_plus_y + x_minus_y) / 2;
        int y = x_plus_y - x;

        return {y, x};
    }
};