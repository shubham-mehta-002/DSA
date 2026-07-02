#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, m;
    vector<vector<int>> vis;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

public:
    int dfs(int row, int col, vector<vector<int>> &grid)
    {
        vis[row][col] = 1;

        int res = 1;
        for (int i = 0; i < 4; i++)
        {
            int newr = row + dx[i];
            int newc = col + dy[i];

            if (newr >= 0 && newc >= 0 && newr < n && newc < m && grid[newr][newc] && !vis[newr][newc])
            {
                res += dfs(newr, newc, grid);
            }
        }

        return res;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<int>(m, 0));
        int maxx = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    maxx = max(maxx, dfs(i, j, grid));
                }
            }
        }

        return maxx;
    }
};