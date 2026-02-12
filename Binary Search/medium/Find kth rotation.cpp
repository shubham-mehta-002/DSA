#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinElIndex(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        int minVal = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid])
            {
                if (nums[minVal] > nums[low])
                {
                    minVal = low;
                }
                low = mid + 1;
            }
            else
            {
                if (nums[minVal] > nums[mid])
                {
                    minVal = mid;
                }
                high = mid - 1;
            }
        }

        return minVal;
    }
    int findKRotation(vector<int> &arr)
    {
        int minElementIndex = findMinElIndex(arr);
        return minElementIndex - 0;
    }
};
