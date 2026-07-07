#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        int sum = 0;
        int res = 0;

        int tens = 0;
        while (n)
        {
            int rem = n % 10;
            if (rem)
            {
                res = rem * pow(10, tens) + res;
                sum += rem;
                tens++;
            }

            n /= 10;
        }

        return 1LL * res * sum;
    }
};