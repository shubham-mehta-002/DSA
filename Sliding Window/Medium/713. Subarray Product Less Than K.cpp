#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int n = nums.size();
        int i = 0;
        int j = 0;

        int curr = 1;
        int cnt = 0;

        while (j < n)
        {
            curr *= nums[j];

            while (curr >= k)
            {
                curr /= nums[i];
                i++;
            }

            cnt += (j - i + 1);
            j++;
        }

        return cnt;
    }
};