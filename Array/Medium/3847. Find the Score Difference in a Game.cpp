
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreDifference(vector<int> &nums)
    {
        bool active = true;
        int score = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
            {
                active = !active;
            }

            if ((i + 1) % 6 == 0)
            {
                active = !active;
            }

            if (active)
            {
                score += nums[i];
            }
        }

        int total = 0;
        for (int n : nums)
        {
            total += n;
        }

        return score - (total - score);
    }
};