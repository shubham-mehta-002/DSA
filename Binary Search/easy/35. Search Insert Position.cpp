#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0;
        int h = nums.size() - 1;
        int index = h + 1;
        while (l <= h)
        {
            int m = l + (h - l) / 2;

            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                index = m;
                h = m - 1;
            }
        }

        return index;
    }
};