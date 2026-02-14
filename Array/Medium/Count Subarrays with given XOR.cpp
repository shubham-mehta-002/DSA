#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        long count = 0;
        int i = 0;
        int j = 0;
        int n = arr.size();

        unordered_map<int, int> mpp;

        int xorVal = 0;

        while (j < n)
        {
            xorVal ^= arr[j];

            if (xorVal == k)
            {
                count++;
            }

            count += mpp[xorVal ^ k];

            mpp[xorVal]++;
            j++;
        }

        return count;
    }
};