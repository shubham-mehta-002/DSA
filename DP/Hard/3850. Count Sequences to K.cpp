
#include <bits/stdc++.h>
using namespace std;

class Solution

{
public:
    int find(
        int index, vector<int> &nums, long long k, long long num, long long den,
        unordered_map<
            int, unordered_map<long long, unordered_map<long long, int>>> &dp)
    {
        if (index == nums.size())
        {
            if (den != 0 && num % den == 0 && num / den == k)
                return 1;
            return 0;
        }

        if (dp.find(index) != dp.end() &&
            dp[index].find(num) != dp[index].end() &&
            dp[index][num].find(den) != dp[index][num].end())
        {
            return dp[index][num][den];
        }

        int count = 0;

        // case : Multiply
        long long newNum = num * nums[index];
        long long newDen = den;
        long long g = gcd(newNum, newDen);
        newNum /= g;
        newDen /= g;

        count += find(index + 1, nums, k, newNum, newDen, dp);

        // case : Leave
        count += find(index + 1, nums, k, num, den, dp);

        // case : Divide
        newNum = num;
        newDen = den * nums[index];
        g = gcd(newNum, newDen);
        newNum /= g;
        newDen /= g;

        count += find(index + 1, nums, k, newNum, newDen, dp);

        return dp[index][num][den] = count;
    }

    int countSequences(vector<int> &nums, long long k)
    {
        int n = nums.size();
        unordered_map<int,
                      unordered_map<long long, unordered_map<long long, int>>>
            dp;
        return find(0, nums, k, 1, 1, dp);
    }
};