#include <bits/stdc++.h>
using namespace std;
class Solution

{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();

        // vector<vector<int>>dp(n,vector<int>(target+1,0));
        vector<int> prev(target + 1, 0);

        prev[0] = 1;
        if (target >= arr[0])
        {
            prev[arr[0]]++;
        }

        int t = target;
        for (int index = 1; index < n; index++)
        {
            vector<int> curr(target + 1, 0);
            for (int target = 0; target <= t; target++)
            {
                int take = 0;
                if (target >= arr[index])
                {
                    take = prev[target - arr[index]];
                }
                int notTake = prev[target];

                curr[target] = (take + notTake);
            }
            prev = curr;
        }
        return prev[target];
    }
};