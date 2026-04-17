#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, int> mpp;

public:
    int findReverse(int num)
    {
        int temp = 0;

        while (num)
        {
            int rem = num % 10;
            temp *= 10;
            temp += rem;
            num /= 10;
        }

        return temp;
    }

    int minMirrorPairDistance(vector<int> &nums)
    {
        int n = nums.size();
        int minn = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int rev = findReverse(nums[i]);
            cout << rev << " ";
            if (mpp.find(nums[i]) != mpp.end())
            {
                minn = min(minn, abs(mpp[nums[i]] - i));
            }

            mpp[rev] = i;
        }

        return minn == INT_MAX ? -1 : minn;
    }
};