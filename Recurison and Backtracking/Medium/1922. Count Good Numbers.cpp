#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    long long pow(int a, long long b)
    {
        if (b == 0)
            return 1;

        long long half = pow(a, b / 2) % MOD;
        long long res = half * half;
        res %= MOD;

        if (b % 2 == 1)
        {
            res *= a;
        }
        return res % MOD;
    }
    int countGoodNumbers(long long n)
    {
        long long odd = n / 2;
        long long even = n - odd;

        return (pow(5, even) * pow(4, odd)) % MOD;
    }
};