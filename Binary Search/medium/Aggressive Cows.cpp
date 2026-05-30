#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int minGap, vector<int> &gaps, int cows)
    {
        int remCows = cows - 1;
        int currGap = 0;
        for (int g : gaps)
        {
            currGap += g;

            if (currGap >= minGap)
            {
                currGap = 0;
                remCows--;
            }

            if (remCows == 0)
            {
                return true;
            }
        }

        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());
        vector<int> temp;
        for (int i = 1; i < stalls.size(); i++)
        {
            temp.push_back(stalls[i] - stalls[i - 1]);
        }

        int l = *min_element(temp.begin(), temp.end());
        int h = accumulate(temp.begin(), temp.end(), 0);

        int ans = l;
        while (l <= h)
        {
            int mid = (l + h) / 2;

            if (isPossible(mid, temp, k))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return ans;
    }
};