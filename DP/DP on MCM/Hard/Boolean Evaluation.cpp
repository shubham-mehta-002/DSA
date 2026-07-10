// https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650

#include <bits/stdc++.h>
using namespace std;

using pp = pair<int, int>;
const int MOD = 1000000007;

int evaluateExp(string &exp)
{
    int n = exp.size();

    vector<vector<pp>> dp(n, vector<pp>(n, {0, 0}));

    // Base cases
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == 'T')
        {
            dp[i][i] = {1, 0};
        }
        else if (exp[i] == 'F')
        {
            dp[i][i] = {0, 1};
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {

            if (i == j)
                continue;

            long long trueCnt = 0;
            long long falseCnt = 0;

            for (int index = i + 1; index < j; index += 2)
            {

                pp left = dp[i][index - 1];
                int lt = left.first;
                int lf = left.second;

                pp right = dp[index + 1][j];
                int rt = right.first;
                int rf = right.second;

                if (exp[index] == '|')
                {
                    trueCnt = (trueCnt + 1LL * lt * rt +
                               1LL * lt * rf +
                               1LL * lf * rt) %
                              MOD;

                    falseCnt = (falseCnt + 1LL * lf * rf) % MOD;
                }
                else if (exp[index] == '&')
                {
                    trueCnt = (trueCnt + 1LL * lt * rt) % MOD;

                    falseCnt = (falseCnt + 1LL * lt * rf +
                                1LL * lf * rt +
                                1LL * lf * rf) %
                               MOD;
                }
                else
                { // '^'
                    trueCnt = (trueCnt + 1LL * lt * rf +
                               1LL * lf * rt) %
                              MOD;

                    falseCnt = (falseCnt + 1LL * lt * rt +
                                1LL * lf * rf) %
                               MOD;
                }
            }

            dp[i][j] = {(int)trueCnt, (int)falseCnt};
        }
    }

    return dp[0][n - 1].first;
}