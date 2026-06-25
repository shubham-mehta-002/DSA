#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int j = 0;

        int minRemovals = n;

        while (i < n)
        {
            while (j < n - 1 && (long)nums[j + 1] <= (long)nums[i] * k)
            {
                j++;
            }

            minRemovals = min(minRemovals, n - (j - i + 1));
            i++;
        }

        return minRemovals;
    }
};