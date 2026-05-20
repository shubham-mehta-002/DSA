#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] >= nums[i - 1])
            {
                continue;
            }
            else
            {
                cnt++;
                if (cnt > 1)
                {
                    return false;
                }
            }
        }

        if (cnt == 0)
            return true;
        if (nums[0] >= nums[n - 1])
            return true;
        return false;
    }
};