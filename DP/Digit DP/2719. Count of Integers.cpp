#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    string minusOne(string &str)
    {
        int i = str.size() - 1;

        while (i >= 0 && str[i] == '0')
        {
            str[i] = '9';
            i--;
        }

        if (i >= 0)
        {
            str[i]--;
        }

        // remove leading zeros
        int start = 0;
        while (start < str.size() - 1 && str[start] == '0')
        {
            start++;
        }

        return str.substr(start);
    }

    int find(int index, bool tight, int minSum, int maxSum,
             string &str, int currSum, int mem[23][2][401])
    {

        if (currSum > maxSum)
            return 0;

        if (index == str.size())
        {
            return (currSum >= minSum && currSum <= maxSum);
        }

        if (mem[index][tight][currSum] != -1)
        {
            return mem[index][tight][currSum];
        }

        int ub = (tight ? str[index] - '0' : 9);
        int cnt = 0;

        for (int dig = 0; dig <= ub; dig++)
        {
            cnt = (cnt + find(index + 1,
                              tight && (dig == ub),
                              minSum, maxSum,
                              str,
                              currSum + dig,
                              mem)) %
                  MOD;
        }

        return mem[index][tight][currSum] = cnt;
    }

    int count(string num1, string num2, int min_sum, int max_sum)
    {
        string minusOneFromNum1 = minusOne(num1);

        int mem1[23][2][401];
        int mem2[23][2][401];

        memset(mem1, -1, sizeof(mem1));
        memset(mem2, -1, sizeof(mem2));

        int res = (find(0, true, min_sum, max_sum, num2, 0, mem1) -
                   find(0, true, min_sum, max_sum, minusOneFromNum1, 0, mem2) +
                   MOD) %
                  MOD;

        return res;
    }
};