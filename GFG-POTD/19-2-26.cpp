#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> missinRange(vector<int> &arr, int low, int high)
    {
        unordered_map<int, int> mpp;
        for (int n : arr)
        {
            if (n >= low && n <= high)
            {
                mpp[n] = 1;
            }
        }

        vector<int> res;
        for (int i = low; i <= high; i++)
        {
            if (mpp.find(i) == mpp.end())
            {
                res.push_back(i);
            }
        }

        return res;
    }
};