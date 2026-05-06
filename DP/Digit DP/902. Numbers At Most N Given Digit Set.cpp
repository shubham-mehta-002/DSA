#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mem[10][2][2];

public:
    int find(int index, bool tight, bool leadingZeros, string &str, vector<string> &digits)
    {
        if (index == str.size())
        {
            return !leadingZeros;
        }

        if (mem[index][tight][leadingZeros] != -1)
        {
            return mem[index][tight][leadingZeros];
        }

        int cnt = 0;

        // dont include any digit ie use 0
        if (leadingZeros)
            cnt += find(index + 1, false, true, str, digits);

        // include digits
        for (int i = 0; i < digits.size(); i++)
        {
            if (tight && digits[i][0] > str[index])
                continue;

            cnt += find(
                index + 1,
                (tight && str[index] == digits[i][0]),
                false,
                str,
                digits);
        }

        return mem[index][tight][leadingZeros] = cnt;
    }
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        string str = to_string(n);

        memset(mem, -1, sizeof(mem));

        return find(0, true, true, str, digits);
    }
};