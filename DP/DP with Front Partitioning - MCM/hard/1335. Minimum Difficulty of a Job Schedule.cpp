#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifficulty(vector<int> &job, int d)
    {
        const int INF = 1e5;
        int n = job.size();
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INF));

        // base case
        dp[n][0] = 0;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int days = 1; days <= d; days++)
            {
                int finalRes = 1e5;
                int maxx = 0;

                for (int i = index; i < job.size(); i++)
                {
                    maxx = max(maxx, job[i]);
                    finalRes = min(
                        finalRes,
                        maxx + dp[i + 1][days - 1]);
                }
                dp[index][days] = finalRes;
            }
        }

        return dp[0][d] == INF ? -1 : dp[0][d];
    }
};