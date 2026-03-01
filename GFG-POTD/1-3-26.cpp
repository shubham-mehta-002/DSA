#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pushZerosToEnd(vector<int> &arr)
    {
        int i = -1;
        int j = 0;

        int n = arr.size();

        while (j < n)
        {
            if (arr[j] != 0)
            {
                i++;
                arr[i] = arr[j];
            }
            j++;
        }
        i++;

        while (i < n)
        {
            arr[i] = 0;
            i++;
        }
    }
};