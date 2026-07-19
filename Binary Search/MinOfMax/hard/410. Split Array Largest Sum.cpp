#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(int maxSum, vector<int> &nums, int k)
    {
        int partitions = 0;

        int sum = 0;
        for (int n : nums)
        {
            if (sum + n <= maxSum)
            {
                sum += n;
            }
            else
            {
                partitions++;
                sum = n;
            }
        }

        partitions++;

        return partitions <= k;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        cout << low << " " << high;
        int ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isValid(mid, nums, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};