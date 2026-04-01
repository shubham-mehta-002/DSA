#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> res;
    int n;
    int m;

public:
    vector<pair<char, pair<int, int>>> dir = {
        {'D', {1, 0}},
        {'L', {0, -1}},
        {'R', {0, 1}},
        {'U', {-1, 0}}};

    void dfs(int i, int j, vector<vector<int>> &maze, string &temp, vector<vector<int>> &vis)
    {
        if (i == n - 1 && j == m - 1)
        {
            res.push_back(temp);
            return;
        }
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int new_r = i + dir[k].second.first;
            int new_c = j + dir[k].second.second;

            if (new_r >= 0 && new_c >= 0 && new_r < n && new_c < m && maze[new_r][new_c] != 0 && !vis[new_r][new_c])
            {
                temp += dir[k].first;
                dfs(new_r, new_c, maze, temp, vis);
                temp.pop_back();
            }
        }
        vis[i][j] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        n = maze.size();
        m = maze[0].size();

        if (maze[0][0] == 0 || maze[n - 1][m - 1] == 0)
        {
            return res;
        }

        vector<vector<int>> vis(n, vector<int>(m, 0));
        string temp = "";

        dfs(0, 0, maze, temp, vis);

        return res;
    }
};