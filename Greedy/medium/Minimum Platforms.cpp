#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPlatform(vector<int> &arr, vector<int> &dep)
    {
        map<int, int> mpp;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
            mpp[dep[i] + 1]--;
        }

        int curr = 0;
        int maxx = 0;

        for (auto it : mpp)
        {
            curr += it.second;
            maxx = max(maxx, curr);
        }

        return maxx;
    }
};
