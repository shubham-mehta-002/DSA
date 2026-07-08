#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        // Transform string: "abba" -> "#a#b#b#a#"
        string t = "#";
        for (char c : s)
        {
            t += c;
            t += '#';
        }

        int n = t.size();
        vector<int> p(n, 0);

        int center = 0, right = 0;
        int maxLen = 0, maxCenter = 0;

        for (int i = 0; i < n; i++)
        {
            int mirror = 2 * center - i;

            if (i < right)
                p[i] = min(right - i, p[mirror]);

            while (i - p[i] - 1 >= 0 &&
                   i + p[i] + 1 < n &&
                   t[i - p[i] - 1] == t[i + p[i] + 1])
            {
                p[i]++;
            }

            if (i + p[i] > right)
            {
                center = i;
                right = i + p[i];
            }

            if (p[i] > maxLen)
            {
                maxLen = p[i];
                maxCenter = i;
            }
        }

        string ans;
        for (int i = maxCenter - maxLen; i <= maxCenter + maxLen; i++)
        {
            if (t[i] != '#')
                ans += t[i];
        }

        return ans;
    }
};