#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size();
        int mx = 0;

        vector<int> prefixGcd(n, 0);

        // nlogn
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        // nlogn
        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0;
        int j = n - 1;

        long long sum = 0;

        // nlogn
        while (i < j)
        {
            sum += 1LL * gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};