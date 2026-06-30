#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> res;

        if (n == 0)
        {
            res.push_back(newInterval);
            return res;
        }

        int i = 0;

        while (i < n)
        {
            // move till there is no overlap [ LEFT SEGMENT ]
            while (i < n && intervals[i][1] < newInterval[0])
            {
                res.push_back(intervals[i]);
                i++;
            }

            int start = newInterval[0];
            int end = newInterval[1];

            // move till they are overlapping
            while (i < n && intervals[i][0] <= newInterval[1])
            {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
                i++;
            }

            res.push_back({start, end});

            // iterate over the no overlap part [RIGHT SEGMENT]
            while (i < n)
            {
                res.push_back(intervals[i]);
                i++;
            }
        }

        return res;
    }
};