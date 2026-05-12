#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {

        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b)
             {
            if(a[1] - a[0] > b[1] - b[0]){
                return true;
            }return false; });

        int minEnergy = 0;

        int remEnergy = 0;

        for (int i = 0; i < tasks.size(); i++)
        {
            if (tasks[i][1] > remEnergy)
            {
                int energyDiff = tasks[i][1] - remEnergy;
                minEnergy += energyDiff;
                remEnergy += energyDiff;
            }

            remEnergy -= tasks[i][0];
        }

        return minEnergy;
    }
};