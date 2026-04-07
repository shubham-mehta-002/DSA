#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        vector<int> prev(n + 1, 0);

        for (int j = 0; j <= n; j++)
        {
            prev[j] = j;
        }

        for (int i = 1; i <= m; i++)
        {
            vector<int> curr(n + 1, 0);
            curr[0] = i;

            for (int j = 1; j <= n; j++)
            {
                int minCost = INT_MAX;

                if (word1[i - 1] == word2[j - 1])
                {
                    minCost = min(minCost, prev[j - 1]);
                }
                else
                {
                    // replace
                    minCost = min(minCost, 1 + prev[j - 1]);

                    // insert
                    minCost = min(minCost, 1 + curr[j - 1]);

                    // delete
                    minCost = min(minCost, 1 + prev[j]);
                }

                curr[j] = minCost;
            }

            prev = curr;
        }

        return prev[n];
    }
};