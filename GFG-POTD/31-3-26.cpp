#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &arr, int k)
    {
        int n = arr.size();

        vector<int> next(2, 0);
        // base case
        next[1] = 0;
        next[0] = arr[n - 1] - k;

        for (int index = n - 2; index >= 0; index--)
        {
            vector<int> curr(2, 0);
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int maxx = 0;
                if (canBuy)
                {
                    maxx = max(maxx, -arr[index] + next[!canBuy]);
                }
                else
                {
                    maxx = max(maxx, arr[index] - k + next[!canBuy]);
                }

                maxx = max(maxx, next[canBuy]);
                curr[canBuy] = maxx;
            }
            next = curr;
        }
        return next[1];
    }
};