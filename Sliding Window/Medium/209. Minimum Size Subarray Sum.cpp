#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int n = nums.size();

        int sum = 0;
        int minn = n + 1;

        while (j < n)
        {
            sum += nums[j];

            while (sum >= target)
            {
                minn = min(minn, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return minn == n + 1 ? 0 : minn;
    }
};