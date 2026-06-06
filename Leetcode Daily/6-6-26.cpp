#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int n = nums.size();
        for (int num : nums)
        {
            right += num;
        }

        vector<int> res;
        for (int n : nums)
        {
            right -= n;
            res.push_back(abs(right - left));
            left += n;
        }

        return res;
    }
};