#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b)
             {
            if(a[1] < b[1]){
                return true;
            }else if(a[1] == b[1]){
                return a[0] < b[0];
            }

            return false; });

        int currentTime = -1e9;
        int removals = 0;
        int n = intervals.size();

        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] >= currentTime)
            {
                currentTime = intervals[i][1];
            }
            else
            {
                removals++;
            }
        }

        return removals;
    }
};