#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long timeNeededAtKSpeed(int speed, int h, vector<int> &piles)
    {
        long long totalHoursNeeded = 0;
        for (int p : piles)
        {
            // totalHoursNeeded += ceil((double)p/speed);
            totalHoursNeeded += (p / speed + (p % speed > 0 ? 1 : 0));
        }
        return totalHoursNeeded;
    }
    int find(int l, int r, int h, vector<int> &piles)
    {
        int k = h;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (timeNeededAtKSpeed(mid, h, piles) <= h)
            {
                k = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return k;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxx = 0;
        for (int p : piles)
        {
            maxx = max(maxx, p);
        }
        return find(1, maxx, h, piles);
    }
};