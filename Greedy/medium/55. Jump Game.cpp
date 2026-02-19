#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > maxIndex)
            {
                return false;
            }

            if (maxIndex >= nums.size() - 1)
            {
                break;
            }

            maxIndex = max(maxIndex, i + nums[i]);
        }

        return true;
    }
};