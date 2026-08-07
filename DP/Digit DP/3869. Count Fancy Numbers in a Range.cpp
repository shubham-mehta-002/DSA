#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long mem[16][2][2][2][2][11][145];

    bool isMonotone(int sum)
    {
        if (sum <= 9)
            return true;

        string str = to_string(sum);

        bool increasing = true;
        bool decreasing = true;

        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] <= str[i - 1])
                increasing = false;

            if (str[i] >= str[i - 1])
                decreasing = false;
        }

        return increasing || decreasing;
    }

    long long find(string &str, int index, bool leadingZeros, bool bounded, bool increasing, bool decreasing, int prev, int sum)
    {
        if (index == str.size())
        {
            if (leadingZeros || sum == 0)
                return 0;
            if (increasing || decreasing || isMonotone(sum))
                return 1LL;
            return 0;
        }

        if (mem[index][leadingZeros][bounded][increasing][decreasing][prev + 1][sum] != -1)
        {
            return mem[index][leadingZeros][bounded][increasing][decreasing][prev + 1][sum];
        }

        long long ans = 0;

        int end = bounded ? str[index] - '0' : 9;
        for (int i = 0; i <= end; i++)
        {
            if (prev == -1)
            {
                ans += find(str, index + 1, leadingZeros && i == 0, bounded && str[index] - '0' == i, true, true, leadingZeros && i == 0 ? -1 : i, sum + i);
            }
            else if (increasing && i > prev)
            {
                ans += find(str, index + 1, leadingZeros && i == 0, bounded && str[index] - '0' == i, true, false, i, sum + i);
            }
            else if (decreasing && i < prev)
            {
                ans += find(str, index + 1, leadingZeros && i == 0, bounded && str[index] - '0' == i, false, true, i, sum + i);
            }
            else
            {
                ans += find(str, index + 1, leadingZeros && i == 0, bounded && str[index] - '0' == i, false, false, i, sum + i);
            }
        }

        return mem[index][leadingZeros][bounded][increasing][decreasing][prev + 1][sum] = ans;
    }

public:
    long long countFancy(long long l, long long r)
    {
        if (r <= 10)
        {
            return r - l + 1;
        }

        string a = to_string(l - 1);
        string b = to_string(r);

        memset(mem, -1, sizeof(mem));
        long long ans_r = find(b, 0, true, true, true, true, -1, 0);

        memset(mem, -1, sizeof(mem));
        ;
        long long ans_l = find(a, 0, true, true, true, true, -1, 0);

        return ans_r - ans_l;
    }
};