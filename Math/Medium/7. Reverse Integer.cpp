#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(int res, int rem)
    {
        if ((res > (INT_MAX / 10)) || (res < (INT_MIN / 10)))
        {
            return false;
        }

        if ((res == INT_MAX / 10) && (INT_MAX - rem < res))
        {
            return false;
        }

        if ((res == INT_MIN / 10) && (INT_MIN - rem > res))
        {
            return false;
        }

        return true;
    }

    int reverse(int x)
    {
        int res = 0;
        while (x)
        {
            int rem = x % 10;
            x /= 10;

            if (!isValid(res, rem))
            {
                return 0;
            }
            res = (res * 10) + rem;
        }

        return res;
    }
};