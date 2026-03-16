#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestBalancedIndex(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;

        long long prod = 1;

        int idx = -1;

        long long totalSum = 0;
        for (int n : nums)
        {
            totalSum += n;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            totalSum -= nums[i];

            if (totalSum == prod)
            {
                return i;
            }
            else if (totalSum < prod)
            {
                break;
            }

            prod *= nums[i];
        }

        return idx;
    }
};