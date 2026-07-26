#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findGcd(int num1, int num2)
    {
        return gcd(num1, num2);
    }
    long long gcdSum(vector<int> &nums)
    {
        int prefixMax = INT_MIN;
        int n = nums.size();

        vector<int> gcdPrefix(n, -1);
        for (int i = 0; i < n; i++)
        {
            prefixMax = max(prefixMax, nums[i]);
            gcdPrefix[i] = findGcd(prefixMax, nums[i]);
        }

        sort(gcdPrefix.begin(), gcdPrefix.end());

        long long sum = 0;
        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            sum += findGcd(gcdPrefix[i], gcdPrefix[j]);
            i++;
            j--;
        }
        return sum;
    }
};