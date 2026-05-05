#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumXOR(vector<int> &arr)
    {
        long long sum = 0;

        for (int bit = 0; bit < 32; bit++)
        {
            int ones = 0;
            int zeros = 0;

            for (int n : arr)
            {
                if (n & (1LL << bit))
                {
                    ones++;
                }
                else
                {
                    zeros++;
                }
            }

            sum += (1LL << bit) * (1LL * ones * zeros);
        }

        return sum;
    }
};