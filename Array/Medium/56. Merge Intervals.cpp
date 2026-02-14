#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        int minEl = intervals[0][0];
        int maxEl = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > maxEl)
            {
                res.push_back({minEl, maxEl});
                minEl = intervals[i][0];
                maxEl = intervals[i][1];
            }
            else
            {
                maxEl = max(maxEl, intervals[i][1]);
            }
        }

        res.push_back({minEl, maxEl});

        return res;
    }
};