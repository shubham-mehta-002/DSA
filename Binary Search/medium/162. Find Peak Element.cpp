#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);

        int l = 1;
        int h = n;

        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid - 1;
            }
            else if (nums[mid] < nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return -1;
    }
};