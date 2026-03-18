#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getLIS(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> lis(n, {1, -1});

        int globalMaxIndex = 0;

        for (int i = 0; i < n; i++)
        {
            int maxx = 0;
            int index = -1;

            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && lis[j].first > maxx)
                {
                    maxx = lis[j].first;
                    index = j;
                }
            }
            lis[i].first += maxx;
            lis[i].second = index;

            if (lis[globalMaxIndex].first < lis[i].first)
            {
                globalMaxIndex = i;
            }
        }

        // backTrack
        vector<int> res;
        while (globalMaxIndex != -1)
        {
            res.push_back(arr[globalMaxIndex]);
            globalMaxIndex = lis[globalMaxIndex].second;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};