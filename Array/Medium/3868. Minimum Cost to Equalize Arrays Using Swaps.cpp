#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &nums1, vector<int> &nums2)
    {
        int xorr = 0;
        // for(int n : nums1) xorr ^= n;
        // for(int n : nums2) xorr ^= n;

        unordered_map<int, int> mpp;
        for (int n : nums1)
        {
            mpp[n]++;
            xorr ^= n;
        }

        int count = nums1.size();

        for (int n : nums2)
        {
            xorr ^= n;
            if (mpp[n])
            {
                mpp[n]--;
                count--;
            }
        }

        if (xorr != 0)
        {
            return -1;
        }
        else
        {
            return count / 2;
        }
    }
};