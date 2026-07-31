#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(string &s1, string &s2, int s1Index, int s2Index, vector<vector<int>> &dp)
    {
        if (s2Index == s2.size())
        {
            return s1Index - 1; // completely done
        }

        if (s1Index == s1.size())
        {
            return -1;
        }

        if (dp[s1Index][s2Index] != -2)
        {
            return dp[s1Index][s2Index];
        }

        // match
        if (s1[s1Index] == s2[s2Index])
        {
            return dp[s1Index][s2Index] = find(s1, s2, s1Index + 1, s2Index + 1, dp);
        }

        return dp[s1Index][s2Index] = find(s1, s2, s1Index + 1, s2Index, dp);
    }
    string minWindow(string &s1, string &s2)
    {
        int minLen = INT_MAX;
        int startIndex = -1;

        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -2));

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == s2[0])
            {
                int lastIndex = find(s1, s2, i + 1, 1, dp);
                if (lastIndex != -1 && lastIndex - i + 1 < minLen)
                {
                    minLen = lastIndex - i + 1;
                    startIndex = i;
                }
            }
        }

        string res = "";
        if (startIndex == -1)
        {
            return "";
        }
        else
        {
            for (int i = startIndex; i < startIndex + minLen; i++)
            {
                res += s1[i];
            }
        }
        return res;
    }
};
