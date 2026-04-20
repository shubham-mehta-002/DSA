#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int l = n - 1; l >= 0; l--)
        {
            int maxx = 0;
            int maxVal = 0;
            for (int i = 0; i < k; i++)
            {
                if (l + i >= n)
                    break;
                maxVal = max(maxVal, arr[i + l]);
                int currSum = maxVal * (i + 1);
                maxx = max(maxx, currSum + dp[l + i + 1]);
            }

            dp[l] = maxx;
        }

        return dp[0];
    }
};