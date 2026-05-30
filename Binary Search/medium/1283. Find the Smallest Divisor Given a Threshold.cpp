#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSum(int div, vector<int> &nums)
    {
        int total = 0;
        for (int n : nums)
        {
            total += (n + div - 1) / div;
        }
        return total;
    }

    int find(int l, int r, vector<int> &nums, int threshold)
    {
        int ans = -1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (getSum(mid, nums) <= threshold)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int maxx = *max_element(nums.begin(), nums.end());

        return find(1, maxx, nums, threshold);
    }
};