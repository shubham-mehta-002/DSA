#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int i = 0;
        int j = 0;

        while (j < n)
        {
            if (j - i > k)
            {
                mpp[nums[i]]--;
                i++;
            }

            if (mpp[nums[j]] > 0)
            {
                return true;
            }
            mpp[nums[j]]++;
            j++;
        }

        return false;
    }
};