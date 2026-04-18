#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rev(int num)
    {
        int r = 0;
        while (num)
        {
            r *= 10;
            r += num % 10;
            num /= 10;
        }
        return r;
    }
    int mirrorDistance(int n)
    {
        return abs(rev(n) - n);
    }
};