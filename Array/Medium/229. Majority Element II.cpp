#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        int cnt1 = 0;
        int cnt2 = 0;

        for (int n : nums)
        {
            if (cnt1 == 0 && el2 != n)
            {
                el1 = n;
                cnt1 = 1;
            }
            else if (cnt2 == 0 && el1 != n)
            {
                el2 = n;
                cnt2 = 1;
            }

            else if (el1 == n)
                cnt1++;
            else if (el2 == n)
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> res;
        cnt1 = 0;
        cnt2 = 0;

        // check for el1;
        for (int n : nums)
        {
            if (n == el1)
                cnt1++;
            if (n == el2)
                cnt2++;
        }

        int minReq = (int)(nums.size() / 3) + 1;
        if (cnt1 >= minReq)
            res.push_back(el1);
        if (cnt2 >= minReq)
            res.push_back(el2);

        return res;
    }
};