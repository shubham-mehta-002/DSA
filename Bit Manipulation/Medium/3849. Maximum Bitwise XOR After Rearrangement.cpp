
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumXor(string s, string t)
    {
        string res = "";
        int n = s.size();

        int zeroCount = 0;
        int oneCount = 0;

        for (char c : t)
        {
            if (c - '0' == 0)
                zeroCount++;
            else
                oneCount++;
        }

        for (char c : s)
        {
            if (c == '1')
            {
                if (zeroCount)
                {
                    res += '1';
                    zeroCount--;
                }
                else
                {
                    res += '0';
                    oneCount--;
                }
            }
            else
            {
                if (oneCount)
                {
                    res += '1';
                    oneCount--;
                }
                else
                {
                    res += '0';
                    zeroCount--;
                }
            }
        }

        return res;
    }
};