#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();
        vector<int> res(n);

        int l = 0;
        int r = n - 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                res[l++] = nums[i];
            }
            if (nums[n - i - 1] > pivot)
            {
                res[r--] = nums[n - i - 1];
            }
        }

        for (int i = l; i <= r; i++)
        {
            res[i] = pivot;
        }

        return res;
    }
};