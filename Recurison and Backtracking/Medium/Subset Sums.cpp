#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> res;

public:
    void find(int index, vector<int> &arr, int sum)
    {
        if (index == arr.size())
        {
            res.push_back(sum);
            return;
        }
        // take
        find(index + 1, arr, sum + arr[index]);
        // not take
        find(index + 1, arr, sum);
    }
    vector<int> subsetSums(vector<int> &arr)
    {
        find(0, arr, 0);
        return res;
    }
};