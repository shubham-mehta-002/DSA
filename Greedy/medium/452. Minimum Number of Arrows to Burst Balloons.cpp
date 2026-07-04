#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });

        int n = points.size();
        int cnt = 0;
        int currEnd = points[0][1];

        int i = 0;
        int j = 0;
        while (j < n)
        {
            while (j < n && points[j][0] <= points[i][1])
            {
                j++;
            }
            cnt++;
            i = j;
        }

        return cnt;
    }
};