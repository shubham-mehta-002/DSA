#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x)
    {
        int i = 0;
        int j = arr2.size() - 1;
        int closest = INT_MAX;
        int resI = -1;
        int resJ = -1;

        while (i < arr1.size() && j >= 0)
        {
            int sum = arr1[i] + arr2[j];

            if (closest > abs(sum - x))
            {
                closest = abs(sum - x);
                resI = i;
                resJ = j;
            }

            if (sum >= x)
            {
                j--;
            }
            else
                i++;
        }

        return {arr1[resI], arr2[resJ]};
    }
};