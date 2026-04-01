#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> res;

public:
    void find(int index, vector<int> &nums)
    {
        if (index == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            find(index + 1, nums);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        find(0, nums);
        return res;
    }
};