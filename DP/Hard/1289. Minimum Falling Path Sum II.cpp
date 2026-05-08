#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<int> next(n, 0);

        // base case
        int min1 = -1, min2 = -1;

        for (int col = 0; col < n; col++)
        {
            next[col] = grid[n - 1][col];

            if (min1 == -1 || grid[n - 1][min1] > grid[n - 1][col])
            {
                min2 = min1;
                min1 = col;
            }
            else if (min2 == -1 || grid[n - 1][min2] > grid[n - 1][col])
            {
                min2 = col;
            }
        }

        for (int row = n - 2; row >= 0; row--)
        {
            cout << grid[row][min1] << " " << grid[row][min2] << "\n";
            vector<int> curr(n, 0);
            int newMin1 = -1, newMin2 = -1;
            for (int col = 0; col < n; col++)
            {

                if (col == min1)
                {
                    curr[col] = grid[row][col] + next[min2];
                }
                else
                {
                    curr[col] = grid[row][col] + next[min1];
                }

                if (newMin1 == -1 || curr[newMin1] > curr[col])
                {
                    newMin2 = newMin1;
                    newMin1 = col;
                }
                else if (newMin2 == -1 || curr[newMin2] > curr[col])
                {
                    newMin2 = col;
                }
            }
            min1 = newMin1;
            min2 = newMin2;
            next = curr;
        }

        return next[min1];
    }
};