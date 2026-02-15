#include <bits/stdc++.h>
using namespace std;
class Solution

{
public:
    int findMinDiff(vector<int> &a, int m)
    {
        sort(a.begin(), a.end());

        int i = 0;
        int j = 0;
        int n = a.size();

        int minDiff = a[n - 1] - a[0];

        while (j < n)
        {
            if (j - i + 1 == m)
            {
                minDiff = min(minDiff, a[j] - a[i]);
                i++;
            }
            j++;
        }

        return minDiff;
    }
};