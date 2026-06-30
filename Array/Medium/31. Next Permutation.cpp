#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        int i = n - 1;
        while (i > 0 && nums[i] <= nums[i - 1])
        {
            i--;
        }

        if (i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int idx = i - 1;
        int val = nums[idx];

        while (i <= n - 1 && nums[i] > val)
        {
            nums[idx] = nums[i];
            i++;
        }
        nums[i - 1] = val;

        reverse(nums.begin() + idx + 1, nums.end());
    }
};