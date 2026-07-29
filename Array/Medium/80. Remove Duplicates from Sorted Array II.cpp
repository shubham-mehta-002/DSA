#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int n = nums.size();

        while (j < n)
        {
            int cnt = 0;
            int val = nums[j];

            while (j < n && val == nums[j] && cnt < 2)
            {
                nums[i] = nums[j];
                i++;
                j++;
                cnt++;
            }

            while (j < n && nums[j] == val)
            {
                j++;
            }
        }

        return i;
    }
};