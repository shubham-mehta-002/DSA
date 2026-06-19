#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int maxx = 0;
        int curr = 0;
        for (auto g : gain)
        {
            curr += g;
            maxx = max(maxx, curr);
        }
        return maxx;
    }
};