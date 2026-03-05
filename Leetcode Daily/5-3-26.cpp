#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int c1 = 0;
        int c2 = 0;
        char bit = '1';

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == bit)
            {
                c2++;
            }
            else
            {
                c1++;
            }

            bit = (bit == '1' ? '0' : '1');
        }

        return min(c1, c2);
    }
};