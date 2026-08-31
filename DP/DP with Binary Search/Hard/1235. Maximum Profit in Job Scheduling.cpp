#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pp;
class Solution
{
    int n;

public:
    int getNextValidIdx(vector<pp> &time, int startTime, int l, int h)
    {
        int ans = n;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (time[mid].first >= startTime)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {

        n = profit.size();
        vector<pp> time;

        for (int i = 0; i < n; i++)
        {
            time.push_back({startTime[i], {endTime[i], profit[i]}});
        }

        sort(time.begin(), time.end());

        // tabulation code
        vector<int> dp(n + 1, 0);

        // base case
        dp[n] = 0;

        for (int index = n - 1; index >= 0; index--)
        {
            int maxProfit = 0;

            // take
            int nextValidIdx = getNextValidIdx(time, time[index].second.first, index + 1, n - 1);
            int take = time[index].second.second + (nextValidIdx != -1 ? dp[nextValidIdx] : 0);

            // not take
            int notTake = dp[index + 1];

            dp[index] = max(take, notTake);
        }

        return dp[0];
    }
};