#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAbsIndex(const vector<int> &nums)
    {
        int n = nums.size();

        int left = 0, right = n - 1;

        // Find the first non-negative element
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }

        // All elements are non-negative
        if (left == 0)
            return 0;

        // All elements are negative
        if (left == n)
            return n - 1;

        // Compare the two closest to zero
        if (abs(nums[left]) < abs(nums[left - 1]))
            return left;
        else
            return left - 1;
    }

    vector<int> sortedSquares(vector<int> &nums)
    {
        int idx = minAbsIndex(nums);
        int i = idx - 1;
        int j = idx + 1;
        int n = nums.size();

        vector<int> res;

        res.push_back(nums[idx] * nums[idx]);

        while (i >= 0 && j < n)
        {
            if (abs(nums[i]) < abs(nums[j]))
            {
                res.push_back(nums[i] * nums[i]);
                i--;
            }
            else
            {
                res.push_back(nums[j] * nums[j]);
                j++;
            }
        }

        while (i >= 0)
        {
            res.push_back(nums[i] * nums[i]);
            i--;
        }

        while (j < n)
        {
            res.push_back(nums[j] * nums[j]);
            j++;
        }

        return res;
    }
};