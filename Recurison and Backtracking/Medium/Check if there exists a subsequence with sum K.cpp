#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find(int index, vector<int> &arr, int target, vector<vector<int>> &dp)
    {
        if (index == arr.size())
        {
            return target == 0;
        }

        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }
        // take
        if (target >= arr[index] && find(index + 1, arr, target - arr[index], dp))
        {
            return true;
        }

        return dp[index][target] = find(index + 1, arr, target, dp);
    }
    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return find(0, arr, k, dp);
    }
};