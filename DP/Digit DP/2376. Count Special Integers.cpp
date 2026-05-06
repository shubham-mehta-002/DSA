#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mem[10][2][2][1023];

public:
    int find(int index, bool tight, bool leadingZeros, int mask, string &str)
    {
        if (index == str.size())
        {
            return !leadingZeros;
        }

        if (mem[index][tight][leadingZeros][mask] != -1)
        {
            return mem[index][tight][leadingZeros][mask];
        }

        int lb = 0;
        int ub = tight ? str[index] - '0' : 9;

        int cnt = 0;
        for (int dig = lb; dig <= ub; dig++)
        {
            if (mask & (1 << dig))
                continue;
            cnt += find(index + 1, tight && (str[index] - '0' == dig), (leadingZeros && dig == 0), (leadingZeros && dig == 0) ? 0 : (mask | (1 << dig)), str);
        }

        return mem[index][tight][leadingZeros][mask] = cnt;
    }

    int countSpecialNumbers(int n)
    {
        string str = to_string(n);
        memset(mem, -1, sizeof(mem));

        return find(0, true, true, 0, str);
    }
};