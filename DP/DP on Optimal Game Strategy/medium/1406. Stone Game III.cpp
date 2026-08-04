#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();

        vector<int> dp(n + 1, INT_MIN);

        dp[n] = 0;

        for (int index = n - 1; index >= 0; index--)
        {
            int sum = 0;
            int maxx = INT_MIN;
            for (int i = index; i < min(n, index + 3); i++)
            {
                sum += stoneValue[i];
                maxx = max(
                    maxx,
                    sum - dp[i + 1]);
            }

            dp[index] = maxx;
        }

        int diff = dp[0];

        if (diff > 0)
        {
            return "Alice";
        }
        else if (diff < 0)
        {
            return "Bob";
        }
        return "Tie";
    }
};