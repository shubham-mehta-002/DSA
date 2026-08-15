#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, m;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int mem[1001][1001];

    const int MOD = 1e9 + 7;

public:
    int find(int row, int col, vector<vector<int>> &grid)
    {
        if (mem[row][col] != -1)
        {
            return mem[row][col];
        }
        int ans = 0;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && grid[newRow][newCol] > grid[row][col])
            {
                ans = (ans + 1 + find(newRow, newCol, grid)) % MOD;
            }
        }

        return mem[row][col] = ans;
    }
    int countPaths(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        memset(mem, -1, sizeof(mem));

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = (ans + 1 + find(i, j, grid)) % MOD;
            }
        }

        return ans;
    }
};