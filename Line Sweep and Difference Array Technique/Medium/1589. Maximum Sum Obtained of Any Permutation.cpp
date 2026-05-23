#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        int n = nums.size();

        vector<long long> diff(n + 1, 0);

        for (auto r : requests)
        {
            diff[r[0]]++;
            diff[r[1] + 1]--;
        }

        long long prefix = 0;
        for (int i = 0; i <= n; i++)
        {
            prefix += diff[i];
            diff[i] = prefix;
        }

        sort(diff.rbegin(), diff.rend());
        sort(nums.rbegin(), nums.rend());

        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            total += (diff[i] * nums[i]);
        }

        return total % MOD;
    }
};