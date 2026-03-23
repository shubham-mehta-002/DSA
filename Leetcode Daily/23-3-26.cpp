#include <bits/stdc++.h>
using namespace std;

class Solution
{
    typedef long long ll;
    int m;
    int n;
    const int MOD = 1e9 + 7;

public:
    int maxProductPath(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        vector<pair<ll, ll>> next(n, {LLONG_MAX, LLONG_MIN});

        // base case
        next[n - 1] = {grid[m - 1][n - 1], grid[m - 1][n - 1]};

        // last row
        // fill last row
        for (int j = n - 2; j >= 0; j--)
        {
            auto [mn, mx] = next[j + 1];
            ll a = mn * grid[m - 1][j];
            ll b = mx * grid[m - 1][j];
            next[j] = {min(a, b), max(a, b)};
        }

        for (int i = m - 2; i >= 0; i--)
        {
            vector<pair<ll, ll>> curr(n, {LLONG_MAX, LLONG_MIN});
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                    continue; // skip base
                ll minProd = LLONG_MAX;
                ll maxProd = LLONG_MIN;

                // up
                if (i + 1 < m)
                {
                    auto [mn, mx] = next[j];

                    if (mn != LLONG_MAX)
                    {
                        minProd = min(minProd, mn * grid[i][j]);
                        maxProd = max(maxProd, mn * grid[i][j]);
                    }
                    if (mx != LLONG_MIN)
                    {
                        minProd = min(minProd, mx * grid[i][j]);
                        maxProd = max(maxProd, mx * grid[i][j]);
                    }
                }

                // left
                if (j + 1 < n)
                {
                    auto [mn, mx] = curr[j + 1];

                    if (mn != LLONG_MAX)
                    {
                        minProd = min(minProd, mn * grid[i][j]);
                        maxProd = max(maxProd, mn * grid[i][j]);
                    }
                    if (mx != LLONG_MIN)
                    {
                        minProd = min(minProd, mx * grid[i][j]);
                        maxProd = max(maxProd, mx * grid[i][j]);
                    }
                }

                curr[j] = {minProd, maxProd};
            }

            next = curr;
        }

        auto [minProd, maxProd] = next[0];

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};