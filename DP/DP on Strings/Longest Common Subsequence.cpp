#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(string &s1, string &s2)
    {
        // vector<vector<int>>dp(s1.size(), vector<int>(s2.size(), 0));

        vector<int> prev(s2.size(), 0);

        for (int index1 = 0; index1 < s1.size(); index1++)
        {
            vector<int> curr(s2.size(), 0);

            for (int index2 = 0; index2 < s2.size(); index2++)
            {
                if (s1[index1] == s2[index2])
                {
                    curr[index2] = 1 + ((index1 > 0 && index2 > 0) ? prev[index2 - 1] : 0);
                }
                else
                {
                    int temp1 = (index1 > 0) ? prev[index2] : 0;
                    int temp2 = (index2 > 0) ? curr[index2 - 1] : 0;

                    curr[index2] = max(temp1, temp2);
                }
            }

            prev = curr;
        }

        return prev[s2.size() - 1];
    }
};
