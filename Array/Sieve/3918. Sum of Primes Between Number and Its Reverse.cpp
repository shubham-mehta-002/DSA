#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void markAllPrimes(int r, vector<int> &isPrime)
    {
        isPrime[0] = 0;
        isPrime[1] = 0;

        for (int i = 2; i * i <= r; i++)
        {
            if (isPrime[i] == 0)
                continue;

            for (int j = i * i; j <= r; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    int getReverseNo(int n)
    {
        int rev = 0;
        while (n)
        {
            int rem = n % 10;
            rev = (rev * 10) + rem;
            n /= 10;
        }

        return rev;
    }
    int sumOfPrimesInRange(int n)
    {
        int revNo = getReverseNo(n);
        int l = min(n, revNo);
        int r = max(n, revNo);

        vector<int> isPrime(r + 1, 1);

        markAllPrimes(r, isPrime);

        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            if (isPrime[i] == 1)
            {
                sum += i;
            }
        }

        return sum;
    }
};