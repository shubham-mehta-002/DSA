#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        int j = 0;
        unordered_map<int, int> mpp;
        int count = 0;
        int maxLen = 0;

        while (j < n)
        {
            if (arr[j] > k)
                count++;
            else
                count--;

            if (count > 0)
            {
                maxLen = max(maxLen, j + 1);
            }

            if (mpp.find(count - 1) != mpp.end())
            {
                maxLen = max(maxLen, j - mpp[count - 1]);
            }

            if (mpp.find(count) == mpp.end())
            {
                mpp[count] = j;
            }
            j++;
        }

        return maxLen;
    }
};