#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double find(double x, int n)
    {
        if (n == 0)
            return 1.0;

        double res = find(x, n / 2);
        res *= res;

        if (abs(n % 2) == 1)
        {
            res *= x;
        }

        return res;
    }
    double myPow(double x, int n)
    {
        double ans = find(x, n);

        if (n < 0)
        {
            return 1 / ans;
        }
        return ans;
    }
};