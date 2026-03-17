#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        int i = 0;
        while (n)
        {
            if (n & 1 == 1)
            {
                count++;
            }
            n >>= 1;
        }

        return count;
    }
};