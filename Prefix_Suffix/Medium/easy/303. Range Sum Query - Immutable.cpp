#include <bits/stdc++.h>
using namespace std;

class NumArray
{
    vector<int> prefixSum;

public:
    NumArray(vector<int> &nums)
    {
        prefixSum.resize(nums.size());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefixSum[i] = sum;
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return prefixSum[right];
        }
        return prefixSum[right] - prefixSum[left - 1];
    }
};
