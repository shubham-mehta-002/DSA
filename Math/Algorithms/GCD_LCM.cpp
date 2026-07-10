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

    int findLCM(int a, int b)
    {
        return (a * b) / gcd(a, b);
    }

    int findGCD(int a, int b)
    {
        return gcd(a, b);
    }
};