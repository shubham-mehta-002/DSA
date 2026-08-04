#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int maxx = 0;
        int minn = INT_MAX;
        unordered_map<int, int> mpp;
        for (auto n : nums)
        {
            mpp[n] = 1;
            maxx = max(maxx, n);
            minn = min(minn, n);
        }

        vector<int> res;
        for (int i = minn; i <= maxx; i++)
        {
            if (mpp.find(i) == mpp.end())
            {
                res.push_back(i);
            }
        }

        return res;
    }
};