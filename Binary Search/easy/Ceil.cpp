#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCeil(vector<int> &arr, int x)
    {
        int l = 0;
        int h = arr.size() - 1;
        int index = -1;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (arr[mid] >= x)
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