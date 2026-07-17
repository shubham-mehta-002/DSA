#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        int n = nums.size();

        int prefixSum = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];

            int currMod = (prefixSum % k + k) % k;

            if (currMod == 0)
            {
                count++;
            }

            int diff = currMod - 0;
            if (mpp.count(currMod))
            {
                count += mpp[currMod];
            }

            mpp[currMod]++;
        }

        return count;
    }
};