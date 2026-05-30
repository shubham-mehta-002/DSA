#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(int days, vector<int> &arr, int m, int k)
    {
        int boq = 0;
        int consec = 0;

        for (int a : arr)
        {
            if (a <= days)
            {
                consec++;
            }
            else
            {
                consec = 0;
            }

            if (consec == k)
            {
                boq++;
                consec = 0;
            }

            if (boq == m)
                return true;
        }

        return false;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (bloomDay.size() < (long)m * k)
        {
            return -1;
        }

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (possible(mid, bloomDay, m, k))
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};