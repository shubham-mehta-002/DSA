#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xorr = 0;
        for (int n : nums)
        {
            xorr ^= n;
        }

        return xorr;
    }
};