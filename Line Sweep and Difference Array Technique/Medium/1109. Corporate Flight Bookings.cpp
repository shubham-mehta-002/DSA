#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> diff(n, 0);
        for (auto b : bookings)
        {
            diff[b[0] - 1] += b[2];
            if (b[1] < n)
            {
                diff[b[1]] -= b[2];
            }
        }

        int prefix = 0;
        for (int i = 0; i < n; i++)
        {
            prefix += diff[i];
            diff[i] = prefix;
        }

        return diff;
    }
};