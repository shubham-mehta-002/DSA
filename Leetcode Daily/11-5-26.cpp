#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void seperate(int n, vector<int> &res)
    {
        int temp = n;
        while (temp)
        {
            int rem = temp % 10;
            res.push_back(rem);
            temp /= 10;
        }
    }

    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            seperate(nums[i], res);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};