#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int odd = 0;
        int even = 0;

        int maxLen = 0;
        while (i < n)
        {
            unordered_map<int, int> m;
            odd = 0;
            even = 0;
            j = i;

            while (j < n)
            {
                if (m[nums[j]] == 0)
                {
                    m[nums[j]]++;
                    if (nums[j] % 2 == 0)
                        even++;
                    else
                        odd++;
                }

                if (even == odd)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                j++;
            }
            i++;
        }

        return maxLen;
    }
};