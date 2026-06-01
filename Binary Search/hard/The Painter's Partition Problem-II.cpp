#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPaint(int timeEachPainterCanHave, vector<int> &arr, int painters)
    {
        int paintersRem = painters;
        int timeRem = 0;

        for (int a : arr)
        {
            if (a > timeEachPainterCanHave)
                return false;

            if (timeRem < a)
            {
                if (paintersRem == 0)
                    return false;
                timeRem = timeEachPainterCanHave;
                paintersRem--;
            }

            timeRem -= a;
        }

        return true;
    }

    int minTime(vector<int> &arr, int k)
    {
        // code here
        int l = *max_element(arr.begin(), arr.end());
        int h = accumulate(arr.begin(), arr.end(), 0);

        int ans = h;
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