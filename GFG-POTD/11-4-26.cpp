#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countIncreasing(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0;
        int j = 1;

        int count = 0;
        while (j < n)
        {
            while (j < n && arr[j] > arr[j - 1])
            {
                j++;
            }

            int size = j - i;

            count += (size * (size - 1) / 2);

            if (j < n)
            {
                i = j;
                j++;
            }
        }

        return count;
    }
};
