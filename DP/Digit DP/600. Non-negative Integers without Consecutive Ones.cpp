#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mem[30][2][2];

public:
    string getBinaryRepresentation(int num)
    {
        string str = "";
        while (num)
        {
            int bit = num & 1;
            if (bit == 0)
            {
                str.push_back('0');
            }
            else
            {
                str.push_back('1');
            }

            num >>= 1;
        }
        reverse(str.begin(), str.end());
        return str;
    }

    int find(int index, bool tight, bool prevValOne, string &str)
    {
        if (index == str.size())
        {
            return 1;
        }

        if (mem[index][tight][prevValOne] != -1)
        {
            return mem[index][tight][prevValOne];
        }

        int lb = 0;
        int ub = (tight ? str[index] - '0' : 1);

        int cnt = 0;
        for (int dig = lb; dig <= ub; dig++)
        {
            if (dig == 1 && prevValOne)
                continue;

            cnt += find(index + 1,
                        tight && str[index] - '0' == dig,
                        dig == 1,
                        str);
        }

        return mem[index][tight][prevValOne] = cnt;
    }

    int findIntegers(int n)
    {
        string str = getBinaryRepresentation(n);

        memset(mem, -1, sizeof(mem));

        return find(0, true, false, str);
    }
};