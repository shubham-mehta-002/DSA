#include <bits/stdc++.h>
using namespace std;
class Solution

{
    vector<vector<int>> res;

public:
    void find(int index, vector<int> &candidates, int target, vector<int> &temp)
    {
        if (index == candidates.size())
        {
            if (target == 0)
            {
                res.push_back(temp);
            }
            return;
        }

        if (target < 0)
            return;

        // take
        if (target >= candidates[index])
        {
            temp.push_back(candidates[index]);
            find(index, candidates, target - candidates[index], temp);

            temp.pop_back();
        }
        // notTake
        find(index + 1, candidates, target, temp);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        find(0, candidates, target, temp);
        return res;
    }
};