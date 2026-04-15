#include <bits/stdc++.h>
using namespace std;
class Solution

{
public:
    int closestTarget(vector<string> &words, string target, int startIndex)
    {
        int n = words.size();
        int minn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (words[i] == target)
            {
                int dist = abs(i - startIndex);
                minn = min(minn, dist);
                minn = min(minn, n - dist);
            }
        }

        return minn == INT_MAX ? -1 : minn;
    }
};