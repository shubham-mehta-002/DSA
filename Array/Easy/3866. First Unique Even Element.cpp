#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqueEven(vector<int> &nums)
    {
        unordered_map<int, pair<int, int>> mpp; // {val ,{count,index}}
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                if (mpp.find(nums[i]) == mpp.end())
                {
                    mpp[nums[i]] = {1, i};
                }
                else
                {
                    mpp[nums[i]].first++;
                }
            }
        }
        int index = nums.size();
        for (unordered_map<int, pair<int, int>>::iterator it = mpp.begin(); it != mpp.end(); it++)
        {
            if ((it->second).first == 1)
            {
                index = min(index, (it->second).second);
            }
        }
        return index == nums.size() ? -1 : nums[index];
    }
};