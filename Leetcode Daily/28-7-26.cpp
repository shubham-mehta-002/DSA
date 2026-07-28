#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int n = s.size();
        int half = n / 2;

        vector<int> freq(26, 0);
        for (int i = 0; i < half; i++)
        {
            freq[s[i] - 'a']++;
        }

        int i = (n / 2);
        string res = "";
        for (int i = 0; i < 26; i++)
        {
            while (freq[i]--)
            {
                res.push_back(i + 'a');
            }
        }

        string rev = res;
        reverse(rev.begin(), rev.end());

        if (n % 2 == 1)
        {
            res.push_back(s[i]);
        }

        res += rev;
        return res;
    }
};