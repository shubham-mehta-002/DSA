#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canAttend(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end());

        int lastTime = 0;
        for (vector<int> &a : arr)
        {
            if (a[0] >= lastTime && a[1] > a[0])
            {
                lastTime = a[1];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};