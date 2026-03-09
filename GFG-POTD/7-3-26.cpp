#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int noOfWays(int m, int n, int x)
    {
        vector<int> prev(x + 1, 0);

        // base case
        prev[0] = 1;

        for (int throwsLeft = 1; throwsLeft <= n; throwsLeft++)
        {
            vector<int> curr(x + 1, 0);

            for (int target = 0; target <= x; target++)
            {
                int count = 0;
                for (int i = 1; i <= m; i++)
                {
                    if (target - i >= 0)
                    {
                        count += prev[target - i];
                    }
                }

                curr[target] = count;
            }
            prev = curr;
        }

        return prev[x];
    }
};