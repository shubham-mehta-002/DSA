#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> res;

public:
    void find(int index, vector<int> &nums, int target, vector<int> &temp)
    {

        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            if (i == index || (i > index && nums[i] != nums[i - 1]))
            {
                temp.push_back(nums[i]);
                find(i + 1, nums, target - nums[i], temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        find(0, candidates, target, temp);
        return res;
    }
};