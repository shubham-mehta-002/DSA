#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        int n = strs.size();
        int j = 0;
        int i = 1;

        while (true)
        {
            if (strs[0].size() <= j)
            {
                break;
            }
            char ch = strs[0][j];

            for (int i = 1; i < n; i++)
            {
                if (j >= strs[i].size() || strs[i][j] != ch)
                {
                    return prefix;
                }
            }
            prefix += ch;
            j++;
        }

        return prefix;
    }
};