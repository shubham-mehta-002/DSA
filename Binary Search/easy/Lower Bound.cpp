#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lowerBound(vector<int> &arr, int target)
    {
        int l = 0;
        int h = arr.size() - 1;
        int index = h + 1;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (arr[mid] >= target)
            {
                index = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return index;
    }
};
