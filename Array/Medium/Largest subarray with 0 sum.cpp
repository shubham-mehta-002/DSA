#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        int n = arr.size();
        int j = 0;

        unordered_map<int, int> prefixSum;
        int sum = 0;

        int maxLen = 0;

        while (j < n)
        {
            sum += arr[j];

            if (sum == 0)
            {
                maxLen = max(maxLen, j + 1);
            }

            if (prefixSum.find(sum) != prefixSum.end())
            {
                maxLen = max(maxLen, j - prefixSum[sum]);
            }
            else
            {
                prefixSum[sum] = j;
            }

            j++;
        }

        return maxLen;
    }
};