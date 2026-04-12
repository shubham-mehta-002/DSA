#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int currentCity, vector<vector<int>> &cost, int track, vector<vector<int>> &dp)
    {
        int n = cost.size();

        if (track == ((1 << n) - 1))
        {
            return cost[currentCity][0];
        }

        if (dp[currentCity][track] != -1)
        {
            return dp[currentCity][track];
        }

        int minCost = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if ((track & (1 << i)) == 0)
            {
                int newTrack = track | (1 << i);
                minCost = min(minCost, cost[currentCity][i] + find(i, cost, newTrack, dp));
            }
        }
        return dp[currentCity][track] = minCost;
    }

    int tsp(vector<vector<int>> &cost)
    {
        int track = 0; // bitmask
        int n = cost.size();
        track = track | (1 << 0);

        vector<vector<int>> dp(n, vector<int>((1 << n), -1));

        return find(0, cost, track, dp);
    }
};