#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findPower(int a, int b)
    {
        if (b == 0)
        {
            return 1;
        }
        long long res = findPower(a, b / 2);
        res *= res;
        if (b % 2 == 1)
        {
            res *= a;
        }

        return res;
    }
    int nthRoot(int n, int m)
    {
        int low = 0;
        int high = m;

        int res = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            long long temp = findPower(mid, n);
            if (temp == 1LL * m)
            {
                return mid;
            }
            else if (temp > 1LL * m)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }
};