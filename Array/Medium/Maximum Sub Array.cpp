#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubarray(vector<int> &arr)
    {
        int maxSum = 0;
        int startIdx = -1;
        int endIdx = -1;
        int sum = 0;

        int i = 0;
        int j = 0;
        int n = arr.size();

        while (j < n)
        {
            if (arr[j] >= 0)
            {
                sum += arr[j];
            }
            else
            {
                sum = 0;
                i = j + 1;
            }

            if (sum > maxSum || (sum == maxSum && endIdx - startIdx + 1 < j - i + 1))
            {
                maxSum = sum;
                startIdx = i;
                endIdx = j;
            }

            j++;
        }

        vector<int> res;

        if (startIdx == -1)
        {
            res.push_back(-1);
            return res;
        }

        for (int i = startIdx; i <= endIdx; i++)
        {
            res.push_back(arr[i]);
        }

        return res;
    }
};