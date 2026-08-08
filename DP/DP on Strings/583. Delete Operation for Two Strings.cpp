#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<int> prev(n2 + 1, 0);
        // base case
        // for indexes - 0  val : 0

        for (int index1 = 1; index1 <= n1; index1++)
        {
            vector<int> curr(n2 + 1, 0);
            for (int index2 = 1; index2 <= n2; index2++)
            {
                int maxLen = 0;

                if (s1[index1 - 1] == s2[index2 - 1])
                {
                    maxLen = max(maxLen, 1 + prev[index2 - 1]);
                }
                else
                {
                    maxLen = max({maxLen,
                                  prev[index2],
                                  curr[index2 - 1]});
                }

                curr[index2] = maxLen;
            }

            prev = curr;
        }

        return prev[n2];
    }
    int minDistance(string word1, string word2)
    {
        int n = (word1.size() + word2.size());
        return n - 2 * lcs(word1, word2);
    }
};