#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int maxx = 0;
        int minn = INT_MAX;

        for (int n : nums)
        {
            maxx = max(maxx, n);
            minn = min(minn, n);
        }

        return (1LL * k * (maxx - minn));
    }
};