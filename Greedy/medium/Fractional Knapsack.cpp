#include <bits/stdc++.h>
using namespace std;
class Solution

{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        vector<pair<double, int>> frac;
        for (int i = 0; i < val.size(); i++)
        {
            frac.push_back({val[i] / (wt[i] * 1.0), wt[i]});
        }

        sort(frac.begin(), frac.end(), [](pair<double, int> &a, pair<double, int> &b)
             { return a.first > b.first; });

        int remainingCapacity = capacity;

        int j = 0;
        double totalVal = 0.0;

        while (capacity >= 0 && j < frac.size())
        {
            int capUsed = min(frac[j].second, remainingCapacity);
            totalVal += capUsed * frac[j].first;

            remainingCapacity -= capUsed;
            j++;
        }

        return totalVal;
    }
};
