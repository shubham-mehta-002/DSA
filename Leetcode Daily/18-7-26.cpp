#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcd(int divisor, int dividend)
    {
        divisor = abs(divisor);
        dividend = abs(dividend);

        if (divisor == 0)
        {
            return dividend;
        }
        return gcd(dividend % divisor, divisor);
    }

    int findGCD(vector<int> &nums)
    {
        int minn = INT_MAX;
        int maxx = INT_MIN;

        for (auto n : nums)
        {
            minn = min(minn, n);
            maxx = max(maxx, n);
        }

        return gcd(minn, maxx);
    }
};