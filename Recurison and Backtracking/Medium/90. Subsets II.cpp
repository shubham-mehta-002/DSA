#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> res;

public:
    void find(int index, vector<int> &nums, vector<int> &temp)
    {
        if (index == nums.size())
        {
            res.push_back(temp);
            return;
        }
        res.push_back(temp);
        for (int i = index; i < nums.size(); i++)
        {
            if (i == index || i > index && nums[i] != nums[i - 1])
            {
                temp.push_back(nums[i]);
                find(i + 1, nums, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        find(0, nums, temp);
        return res;
    }
};