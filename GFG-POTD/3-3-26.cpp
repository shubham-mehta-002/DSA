#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalElements(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> mpp;
        int i = 0;
        int j = 0;

        int maxLen = 0;

        while (j < n)
        {
            mpp[arr[j]]++;

            if (mpp.size() > 2)
            {
                mpp[arr[i]]--;
                if (mpp[arr[i]] == 0)
                {
                    mpp.erase(arr[i]);
                }
                i++;
            }
            else
            {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }

        return maxLen;
    }
};