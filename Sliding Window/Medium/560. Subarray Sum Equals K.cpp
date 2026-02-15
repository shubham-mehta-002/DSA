#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        int prefixSum = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];

            if (prefixSum == k)
            {
                count++;
            }
            count += m[prefixSum - k];

            m[prefixSum]++;
        }

        return count;
    }
};