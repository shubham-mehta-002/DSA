#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int countPartitions(vector<int> &arr, int diff)
    {
        int n = arr.size();
        int total = 0;
        for (int a : arr)
            total += a;

        if ((total - diff) % 2 != 0 || total - diff < 0)
            return 0;

        int target = (total - diff) / 2;

        vector<int> prev(target + 1, 0);

        // base case
        prev[0] = 1;
        prev[arr[0]] += 1;

        for (int index = 1; index < n; index++)
        {
            vector<int> curr(target + 1, 0);
            for (int sum = 0; sum <= target; sum++)
            {
                int count = 0;

                if (sum - arr[index] >= 0)
                    count += prev[sum - arr[index]];
                count += prev[sum];

                curr[sum] = count;
            }
            prev = curr;
        }
        return prev[target];
    }
};