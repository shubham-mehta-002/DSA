#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime,
                           vector<int> &landDuration,
                           vector<int> &waterStartTime,
                           vector<int> &waterDuration)
    {

        int n1 = landStartTime.size();
        int n2 = waterStartTime.size();

        int ans = INT_MAX;

        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {

                // land -> water
                int landEnd = landStartTime[i] + landDuration[i];
                int landToWater =
                    max(landEnd, waterStartTime[j]) + waterDuration[j];

                // water -> land
                int waterEnd = waterStartTime[j] + waterDuration[j];
                int waterToLand =
                    max(waterEnd, landStartTime[i]) + landDuration[i];

                ans = min({ans, landToWater, waterToLand});
            }
        }

        return ans;
    }
};