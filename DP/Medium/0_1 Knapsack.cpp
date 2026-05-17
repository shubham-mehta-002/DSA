#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();

        vector<int> prev(W + 1, 0);

        // base case
        for (int i = 0; i <= W; i++)
        {
            if (wt[0] <= i)
            {
                prev[i] = val[0];
            }
        }

        for (int index = 1; index < n; index++)
        {
            vector<int> curr(W + 1, 0);
            for (int capacity = 0; capacity <= W; capacity++)
            {
                int take = 0;
                if (capacity >= wt[index])
                {
                    take = val[index] + prev[capacity - wt[index]];
                }
                int notTake = prev[capacity];

                curr[capacity] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[W];
    }
};