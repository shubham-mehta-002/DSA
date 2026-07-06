#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             {
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0]; });

        int n = intervals.size();
        int i = 0;
        int j = 1;
        int covered = 0;

        while (j < n)
        {
            while (j < n && intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1])
            {
                covered++;
                j++;
            }
            i = j;
            j++;
        }
        return n - covered;
    }
};