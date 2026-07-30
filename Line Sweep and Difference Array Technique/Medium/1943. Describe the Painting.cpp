#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
    {
        int n = segments.size();
        map<int, long long> mpp;

        for (auto s : segments)
        {
            mpp[s[0]] += s[2];
            mpp[s[1]] -= s[2];
        }
        vector<vector<long long>> res;
        map<int, long long>::iterator it = mpp.begin();
        long long prefixSum = it->second;
        int prev = it->first;
        it++;

        for (; it != mpp.end(); it++)
        {
            if (prefixSum > 0)
                res.push_back({prev, it->first, prefixSum});
            prefixSum += it->second;
            prev = it->first;
        }

        return res;
    }
};