#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getLIS(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> parent(n, -1);
        vector<int> dp(n, 1);
        int maxIdx = 0;
        int maxx = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > maxx)
                    {
                        maxIdx = i;
                    }
                    maxx = max(maxx, dp[i]);
                }
            }
        }

        vector<int> res;
        int start = maxIdx;

        while (maxIdx != -1)
        {
            res.push_back(arr[maxIdx]);
            maxIdx = parent[maxIdx];
        }

        reverse(res.begin(), res.end());

        return res;
    }
};