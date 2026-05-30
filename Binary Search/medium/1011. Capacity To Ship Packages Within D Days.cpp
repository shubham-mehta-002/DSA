#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canShip(int capacity, vector<int> &weights, int days)
    {
        int daysLeft = days;
        int capLeft = 0;

        for (int a : weights)
        {
            if (a > capacity)
                return false;

            if (capLeft < a)
            {
                if (daysLeft == 0)
                    return false;
                capLeft = capacity;
                daysLeft--;
            }

            capLeft -= a;
        }
        return true;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);

        int ans = h;

        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (canShip(mid, weights, days))
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