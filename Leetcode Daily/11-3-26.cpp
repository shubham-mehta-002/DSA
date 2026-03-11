#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if (n == 0)
            return 1;
        int temp = 0;
        for (int i = 0; i < (int)(log2(n)) + 1; i++)
        {
            temp <<= 1;
            temp |= 1;
        }

        return temp ^ n;
    }
};