#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string &a, string &b)
    {
        if (b.size() != a.size() + 1)
            return false;
        int i = 0;
        int j = 0;

        bool skipped = false;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                if (skipped)
                    return false;
                // skip
                j++;
                skipped = true;
            }
        }
        // if(skipped == false) j++;

        return true;
    }
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();

        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });

        vector<int> dp(n, 1);
        int maxx = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isValid(words[j], words[i]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    maxx = max(maxx, dp[i]);
                }
            }
        }

        return maxx;
    }
};