#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPaint(int maxTime, vector<int> &arr, int k)
    {
        int time = 0;
        int painters = 1;

        for (int a : arr)
        {
            if (time + a <= maxTime)
            {
                time += a;
            }
            else
            {
                painters++;
                time = a;
            }

            if (painters > k)
                return false;
        }

        return true;
    }

    int minTime(vector<int> &arr, int k)
    {
        int l = *max_element(arr.begin(), arr.end());
        int h = accumulate(arr.begin(), arr.end(), 0);

        int ans = -1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (canPaint(mid, arr, k))
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