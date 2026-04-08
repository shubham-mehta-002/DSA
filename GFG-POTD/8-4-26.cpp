#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        int n = arr.size();
        int zero = 0;
        int one = n - 1;

        while (zero < one)
        {
            while (zero < n && arr[zero] == 0)
                zero++;
            while (one < n && arr[one] == 1)
                one--;

            if (zero < one)
            {
                swap(arr[zero], arr[one]);
                zero++;
                one--;
            }
        }
    }
};