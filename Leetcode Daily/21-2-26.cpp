#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int num)
    {
        int count = 0;
        bitset<32> b(num);
        for (int i = 0; i <= 31; i++)
        {
            if (b[i] == 1)
                count++;
        }
        return count;
    }

    bool isPrime(int num)
    {
        if (num < 2)
            return false;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int countPrimeSetBits(int left, int right)
    {
        int count = 0;
        for (int i = left; i <= right; i++)
        {
            int bits = find(i);
            if (isPrime(bits))
            {
                count++;
            }
        }

        return count;
    }
};