#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        vector<int> arr;
        arr.push_back(0);
        for (int cut : cuts)
            arr.push_back(cut);
        arr.push_back(n);

        sort(arr.begin(), arr.end());

        int size = arr.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));

        for (int l = size - 1; l >= 0; l--)
        {
            for (int r = 0; r < size; r++)
            {
                int minCost = INT_MAX;
                for (int i = l + 1; i < r; i++)
                {
                    minCost = min(minCost, arr[r] - arr[l] + dp[l][i] + dp[i][r]);
                }
                dp[l][r] = (minCost == INT_MAX ? 0 : minCost);
            }
        }

        return dp[0][size - 1];
    }
};