#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> diff(1001, 0);
        for (auto t : trips)
        {
            diff[t[1]] += t[0];
            diff[t[2]] -= t[0];
        }

        int tot = 0;

        for (int d : diff)
        {
            tot += d;
            if (tot > capacity)
            {
                return false;
            }
        }

        return true;
    }
};