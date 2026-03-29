#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();

        vector<int> prev(capacity + 1, 0);
        // base case
        for (int i = 0; i <= capacity; i++)
        {
            prev[i] = (i / wt[0]) * val[0];
        }

        for (int index = 1; index < n; index++)
        {
            vector<int> curr(capacity + 1, 0);
            for (int cap = 0; cap <= capacity; cap++)
            {
                int take = 0;
                if (cap >= wt[index])
                {
                    take = val[index] + curr[cap - wt[index]];
                }

                int notTake = prev[cap];

                curr[cap] = max(take, notTake);
            }

            prev = curr;
        }

        return prev[capacity];
    }
};