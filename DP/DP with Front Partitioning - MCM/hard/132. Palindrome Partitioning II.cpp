#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mem[2001];

public:
    bool isPalin(int from, int to, string &s)
    {
        while (from <= to)
        {
            if (s[from] != s[to])
            {
                return false;
            }

            from++;
            to--;
        }
        return true;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            int minCuts = s.size() + 1;
            for (int i = index; i < s.size(); i++)
            {
                if (isPalin(index, i, s))
                {
                    minCuts = min(
                        minCuts,
                        1 + dp[i + 1]);
                }

                dp[index] = minCuts;
            }
        }
        return dp[0] - 1;
    }
};