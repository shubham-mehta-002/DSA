#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> res;

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        int i = 0;
        int j = 0;
        int n1 = firstList.size();
        int n2 = secondList.size();

        while (i < n1 && j < n2)
        {
            int maxStart = max(firstList[i][0], secondList[j][0]);
            int minEnd = min(firstList[i][1], secondList[j][1]);

            if (maxStart < minEnd)
            {
                res.push_back({maxStart, minEnd});
            }
            else if (maxStart == minEnd)
            {
                res.push_back({maxStart, maxStart});
            }

            if (firstList[i][1] < secondList[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return res;
    }
};