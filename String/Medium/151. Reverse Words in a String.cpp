#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseSubStringAndAddToResult(int i, int j, string &s, string &res)
    {
        for (int k = j; k >= i; k--)
        {
            res += s[k];
        }
    }

    string reverseWords(string s)
    {
        string res = "";
        int i = 0, j = 0;
        int n = s.size();

        while (j < n)
        {
            while (j < n && s[j] == ' ')
                j++;

            if (j >= n)
                break;

            if (!res.empty())
                res += ' ';

            i = j;

            while (j < n && s[j] != ' ')
                j++;

            reverseSubStringAndAddToResult(i, j - 1, s, res);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
