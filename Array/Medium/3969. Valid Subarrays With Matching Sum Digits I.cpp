#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(long long sum, int x)
    {
        // Last digit
        if (sum % 10 != x)
        {
            return false;
        }

        // First digit
        long long t = sum;
        while (t >= 10)
        {
            t /= 10;
        }

        return t == x;
    }

    int countValidSubarrays(vector<int> &nums, int x)
    {
        int n = nums.size();

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            long long sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += nums[j];

                if (isValid(sum, x))
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};