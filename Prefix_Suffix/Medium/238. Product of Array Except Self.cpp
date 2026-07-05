#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> res(n, 0);
        int curr = 1;
        for (int i = 0; i < n; i++)
        {
            res[i] = curr;
            curr *= nums[i];
        }

        int right = 1;
        int j = n - 1;

        while (j >= 0)
        {
            res[j] = res[j] * right;
            right = right * nums[j];
            j--;
        }

        return res;
    }
};