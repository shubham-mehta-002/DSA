#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSum(int first, int last, int n)
    {
        return n * (first + last) / 2;
    }

    int findGcd(int a, int b)
    {
        if (a == 0)
            return b;
        return findGcd(b % a, a);
    }

    int gcdOfOddEvenSums(int n)
    {
        return findGcd(getSum(1, (n * 2) - 1, n), getSum(2, 2 * n, n));
    }
};