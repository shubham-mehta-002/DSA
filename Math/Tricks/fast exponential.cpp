/*
    Suppose we want to calculate a^b :

    "SLOW EXPONENTIAL" : We can multiply a by itself b times, which will take O(b) time.

    "FAST EXPONENTIAL" : We can use the property that a^b = (a^(b/2))^2 if b is even,
            and a^b = a * (a^(b-1)) if b is odd.
        This allows us to calculate a^b in O(log b) time.
*/

#include <bits/stdc++.h>
using namespace std;

int findPower(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }

    long long half = findPower(a, b / 2);
    long long res = half * half;

    if (b % 2 == 1)
    {
        res *= a;
    }

    return res;
}