#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lowest(vector<int> &nums, int target)
    {
        int l = 0;
        int h = nums.size() - 1;

        int index = -1;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (nums[mid] >= target)
            {
                index = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return (index != -1 && nums[index] == target) ? index : -1;
    }

    int highest(vector<int> &nums, int target)
    {
        int l = 0;
        int h = nums.size() - 1;

        int index = -1;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (nums[mid] > target)
            {
                h = mid - 1;
            }
            else
            {
                index = mid;
                l = mid + 1;
            }
        }

        return (index != -1 && nums[index] == target) ? index : -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return {-1, -1};
        }
        int l = lowest(nums, target);
        int h = highest(nums, target);

        if (l == -1)
        {
            return {-1, -1};
        }

        return {l, h};
    }
};