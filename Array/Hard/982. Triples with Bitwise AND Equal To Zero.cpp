#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        int n = nums.size();
        int tot = 0;
        unordered_map<int, int> mpp;

        // O(n^2)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int res = (nums[i] & nums[j]);
                mpp[res]++;
            }
        }

        for (int n : nums)
        {
            for (auto it : mpp)
            {
                if ((n & it.first) == 0)
                {
                    tot += it.second;
                }
            }
        }

        return tot;
    }
};