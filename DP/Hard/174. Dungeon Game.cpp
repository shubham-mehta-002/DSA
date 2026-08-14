#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int n = dungeon.size();
        int m = dungeon[0].size();

        const int INF = 1e8;

        vector<int> next(m, INF);

        for (int row = n - 1; row >= 0; row--)
        {
            vector<int> curr(m, INF);

            for (int col = m - 1; col >= 0; col--)
            {

                // Bottom-right cell
                if (row == n - 1 && col == m - 1)
                {
                    curr[col] = max(
                        1,
                        1 - dungeon[row][col]);
                    continue;
                }

                int right = INF;
                int down = INF;

                if (col + 1 < m)
                {
                    right = max(
                        curr[col + 1] - dungeon[row][col],
                        1);
                }

                if (row + 1 < n)
                {
                    down = max(
                        next[col] - dungeon[row][col],
                        1);
                }

                curr[col] = min(right, down);
            }

            next = curr;
        }

        return next[0];
    }
};