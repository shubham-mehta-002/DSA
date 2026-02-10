#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(vector<int> &arr, int value)
    {
        int s = 0;
        for (int a : arr)
        {
            // s += ceil(a/value);
            s += (a + value - 1) / value;
        }

        return s;
    }

    int findMax(vector<int> &arr)
    {
        int maxVal = INT_MIN;
        for (int a : arr)
        {
            maxVal = max(maxVal, a);
        }
        return maxVal;
    }

    int kokoEat(vector<int> &arr, int k)
    {
        int n = arr.size();

        int l = 1;
        int h = findMax(arr);

        int minS = h;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            int timeToEat = find(arr, mid);
            // cout << "{" << mid << "," << timeToEat <<"}" << " ";

            if (timeToEat > k)
            {
                l = mid + 1;
            }
            else
            {
                minS = min(mid, minS);
                h = mid - 1;
            }
        }

        return minS;
    }
};