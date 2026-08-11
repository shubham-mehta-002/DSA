#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(int speed, vector<int> &dist, double hour)
    {
        double time = 0.0;

        for (auto d : dist)
        {
            double currTime = (d * 1.0 / speed);
            time += currTime;

            if (time > hour)
            {
                return false;
            }

            time = ceil(time) * 1.0;
        }

        return true;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int l = 1;
        int h = 1e7;

        int ans = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2;

            if (isValid(mid, dist, hour))
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