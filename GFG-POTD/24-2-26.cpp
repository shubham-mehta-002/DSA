#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2)
    {
        unordered_map<int, int> mpp;
        int n = a1.size();

        int j = 0;
        int sum1 = 0;
        int sum2 = 0;
        int maxLen = 0;

        while (j < n)
        {
            sum1 += a1[j];
            sum2 += a2[j];

            int diff = sum2 - sum1;

            if (diff == 0)
            {
                maxLen = max(maxLen, j + 1);
            }

            if (mpp.find(diff) != mpp.end())
            {
                maxLen = max(maxLen, j - mpp[diff]);
            }
            else
            {
                mpp[diff] = j;
            }

            j++;
        }

        return maxLen;
    }
};