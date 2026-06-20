#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLights(vector<int> &lights)
    {
        int n = lights.size();
        vector<int> temp(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (lights[i] > 0)
            {
                int from = max(0, i - lights[i]);
                int to = i + lights[i] + 1;

                temp[from] += 1;
                if (to < n)
                    temp[to] -= 1;
            }
        }

        int curr = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            curr += temp[i];

            if (curr == 0)
            {
                int from = i;
                int to = i + 3;

                temp[from] += 1;
                if (to < n)
                    temp[to] -= 1;

                res++;
                curr++;
            }
        }

        return res;
    }
};