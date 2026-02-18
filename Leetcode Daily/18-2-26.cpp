#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int bit = n & 1;
        int temp = n;

        while (temp)
        {
            if ((temp & 1) == bit)
            {
                bit = (bit == 0 ? 1 : 0);
                temp = temp >> 1;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};