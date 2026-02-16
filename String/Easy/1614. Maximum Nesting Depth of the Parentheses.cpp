#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int count = 0;
        int maxCount = 0;

        for (char c : s)
        {
            if (c == '(')
                count++;
            maxCount = max(maxCount, count);
            if (c == ')')
                count--;
        }

        return maxCount;
    }
};