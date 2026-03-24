#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> p(m, vector<int>(n, 1));
        vector<vector<int>> res(m, vector<int>(n, 1));

        long long prefixProd = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = (res[i][j] * prefixProd) % 12345;
                prefixProd = (prefixProd * grid[i][j]) % 12345;
            }
        }

        long long suffixProd = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                res[i][j] = (res[i][j] * suffixProd) % 12345;
                suffixProd = (suffixProd * grid[i][j]) % 12345;
            }
        }

        return res;
    }
};