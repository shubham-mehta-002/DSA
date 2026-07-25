#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    vector<vector<int>> vis;

public:
    void solve(int row, int col, vector<vector<int>> &res, vector<vector<int>> &grid, int color)
    {
        vis[row][col] = 1;
        int cellColor = grid[row][col];

        int validNbrs = 0;
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && grid[newRow][newCol] == cellColor)
            {
                validNbrs++;
                if (!vis[newRow][newCol])
                {
                    solve(newRow, newCol, res, grid, color);
                }
            }
        }

        if (validNbrs != 4)
        {
            res[row][col] = color;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        n = grid.size();
        m = grid[0].size();

        vis.resize(n, vector<int>(m, 0));

        vector<vector<int>> res = grid;

        solve(row, col, res, grid, color);
        return res;
    }
};