#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        int xLimit = (x + k - 1);

        for (int i = x; i < x + (k / 2); i++)
        {
            for (int j = y; j < y + k; j++)
            {
                // swap
                swap(grid[i][j], grid[xLimit - (i - x)][j]);
            }
        }

        return grid;
    }
};