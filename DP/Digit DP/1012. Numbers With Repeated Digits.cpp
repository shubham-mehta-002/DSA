#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mem[10][2][2][2050][2];

public:
    int find(int index, bool tight, bool leadingZerosOnly, int mask, bool isRepeated, string &str)
    {
        if (index == str.size())
        {
            return isRepeated;
        }

        if (mem[index][tight][leadingZerosOnly][mask][isRepeated] != -1)
        {
            return mem[index][tight][leadingZerosOnly][mask][isRepeated];
        }

        int lb = 0;
        int ub = (tight ? str[index] - '0' : 9);

        int count = 0;
        for (int dig = lb; dig <= ub; dig++)
        {
            count += find(
                index + 1,
                (tight && str[index] - '0' == dig),
                (leadingZerosOnly && dig == 0),
                ((leadingZerosOnly && dig == 0) ? mask : (mask | 1 << dig)),
                ((leadingZerosOnly && dig == 0) ? isRepeated : isRepeated || (mask & 1 << dig)),
                str);
        }

        return mem[index][tight][leadingZerosOnly][mask][isRepeated] = count;
    }
    int numDupDigitsAtMostN(int n)
    {
        string str = to_string(n);
        memset(mem, -1, sizeof(mem));

        return find(0, true, true, 0, false, str);
    }
};