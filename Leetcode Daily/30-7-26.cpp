#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        int ans = 0;
        int n = word.size();
        int counter = 1;
        while (n)
        {
            int temp = min(n, 8);
            ans += temp * counter;

            counter++;
            n -= min(n, 8);
        }

        return ans;
    }
};