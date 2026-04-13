#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int minn = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                minn = min(minn, abs(i - start));
            }
        }

        return minn;
    }
};