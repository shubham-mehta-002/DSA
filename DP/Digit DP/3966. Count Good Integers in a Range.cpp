#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long mem[16][2][2][11];

public:
    long long find(int index, string &s, bool leadingZeros, bool bound, int prev, int k)
    {
        if (index == s.size())
        {
            return leadingZeros ? 0 : 1;
        }

        if (mem[index][leadingZeros][bound][prev] != -1)
        {
            return mem[index][leadingZeros][bound][prev];
        }

        int limit = 9;
        if (bound)
        {
            limit = s[index] - '0';
        }

        long long tot = 0;
        for (int i = 0; i <= limit; i++)
        {
            if (!leadingZeros && prev != 10 && abs(i - prev) > k)
                continue;

            tot += find(
                index + 1,
                s,
                leadingZeros && i == 0,
                bound && s[index] - '0' == i,
                leadingZeros && i == 0 ? 10 : i,
                k);
        }

        return mem[index][leadingZeros][bound][prev] = tot;
    }

    long long soln(string &str, int k)
    {
        memset(mem, -1, sizeof(mem));
        return find(0, str, true, true, 10, k);
    }

    long long goodIntegers(long long l, long long r, int k)
    {
        string str1 = to_string(l - 1);
        string str2 = to_string(r);

        return soln(str2, k) - soln(str1, k);
    }
};