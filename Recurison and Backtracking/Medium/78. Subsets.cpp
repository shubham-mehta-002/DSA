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

        // take
        temp.push_back(nums[index]);
        find(index + 1, nums, temp);

        temp.pop_back();

        // notTake
        find(index + 1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        find(0, nums, temp);
        return res;
    }
};