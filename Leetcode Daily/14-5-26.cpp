#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        int maxx = 0;
        unordered_map<int, int> mpp;

        for (int n : nums)
        {
            maxx = max(maxx, n);
            mpp[n]++;
        }

        // size must be maxx + 1
        if (nums.size() != maxx + 1)
            return false;

        for (int i = 1; i < maxx; i++)
        {
            if (mpp[i] != 1)
            {
                return false;
            }
        }

        // maximum element must appear twice
        if (mpp[maxx] != 2)
        {
            return false;
        }

        return true;
    }
};