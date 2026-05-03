#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(int dig)
    {
        if (dig == 0 || dig == 1 || dig == 8)
        {
            return false;
        }

        return true;
    }
    int find(int index, bool tight, bool leadingZeros, bool validTillNow, string &s, vector<vector<vector<vector<int>>>> &mem)
    {
        if (s.size() == index)
        {
            return validTillNow;
        }

        if (mem[index][tight][leadingZeros][validTillNow] != -1)
        {
            return mem[index][tight][leadingZeros][validTillNow];
        }

        int lb = 0;
        int ub = (tight ? s[index] - '0' : 9);

        int cnt = 0;
        for (int dig = lb; dig <= ub; dig++)
        {
            if (dig == 3 || dig == 4 || dig == 7)
                continue;
            cnt += find(index + 1, (tight && dig == s[index] - '0'), (leadingZeros && dig == 0), (isValid(dig) || validTillNow), s, mem);
        }

        return mem[index][tight][leadingZeros][validTillNow] = cnt;
    }

    int rotatedDigits(int n)
    {
        string str = to_string(n);
        // max value is 10000 so maxTotalDigits -> 5
        vector<vector<vector<vector<int>>>> mem(5, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1)))); // [index][tight][leadingZeros][validTillNow]
        return find(0, true, true, false, str, mem);
    }
};