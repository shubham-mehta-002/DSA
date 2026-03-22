#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

public:
    int orangesRot(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (mat[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        int time = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool rotten = false;
            while (size--)
            {
                auto [i, j] = q.front();

                for (int k = 0; k < 4; k++)
                {
                    int new_r = i + dx[k];
                    int new_c = j + dy[k];

                    if (new_r >= 0 && new_c >= 0 && new_r < m && new_c < n && mat[new_r][new_c] == 1)
                    {
                        mat[new_r][new_c] = 2;
                        q.push({new_r, new_c});
                        fresh--;
                        rotten = true;
                    }
                }

                q.pop();
            }
            if (rotten)
                time++;
        }

        return fresh == 0 ? time : -1;
    }
};