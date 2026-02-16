#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int i = -1;
        int j = 0;

        int n = s.size();
        int count = 0;
        string res = "";
        while (j < n)
        {
            if (s[j] == '(')
            {
                if (count > 0)
                {
                    res.push_back(s[j]);
                }
                count++;
            }
            else
            {
                if (count > 1)
                {
                    res.push_back(s[j]);
                }
                count--;
            }

            j++;
        }

        return res;
    }
};