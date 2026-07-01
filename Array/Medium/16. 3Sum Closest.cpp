#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int val = 1e8;

        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == target)
                {
                    return sum;
                }
                else if (sum > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }

                if (abs(val - target) > abs(sum - target))
                {
                    val = sum;
                }
            }
        }

        return val;
    }
};