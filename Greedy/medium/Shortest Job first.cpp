#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        // code here
        sort(bt.begin(), bt.end());
        long long totalWT = 0;
        long long ttime = 0;

        for (int b : bt)
        {
            totalWT += ttime;
            ttime += b;
        }

        return totalWT / bt.size();
    }
};