#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int checkRecord(int n)
    {
        vector<vector<int>> prev(3, vector<int>(4, 0));

        // base case
        for (int ab = 0; ab < 2; ab++)
        {
            for (int late = 0; late < 3; late++)
            {
                prev[ab][late] = 1;
            }
        }

        for (int day = 1; day <= n; day++)
        {
            vector<vector<int>> curr(3, vector<int>(4, 0));
            for (int absent = 0; absent <= 2; absent++)
            {
                for (int late = 0; late <= 3; late++)
                {
                    if (absent == 2 || late == 3)
                    {
                        curr[absent][late] = 0;
                        continue;
                    }

                    long long ways = 0;
                    // absent
                    ways += prev[absent + 1][0];

                    // late
                    ways += prev[absent][late + 1];

                    // present
                    ways += prev[absent][0];

                    curr[absent][late] = ways % MOD;
                }
            }
            prev = curr;
        }

        return prev[0][0];
    }
};