#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        long count = 0;
        unordered_map<int, int> mpp;

        int xorr = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            xorr = xorr ^ arr[i];

            if (xorr == k)
            {
                count++;
            }

            int diff = k ^ xorr;

            count += mpp[diff];

            mpp[xorr]++;
        }

        return count;
    }
};