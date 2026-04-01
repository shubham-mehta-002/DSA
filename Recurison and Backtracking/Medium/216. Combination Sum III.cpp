#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> res;

public:
    void find(int l, int r, int k, int n, vector<int> &temp)
    {
        if (n < 0)
            return;

        if (k == 0)
        {
            if (n == 0)
                res.push_back(temp);
            return;
        }
        for (int i = l; i <= r; i++)
        {
            temp.push_back(i);
            find(i + 1, r, k - 1, n - i, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> temp;
        find(1, 9, k, n, temp);
        return res;
    }
};