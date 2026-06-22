#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        vector<int> temp(26, 0);
        for (char c : text)
        {
            temp[c - 'a']++;
        }

        string balloon = "balloon";
        unordered_map<int, int> required;
        for (char c : balloon)
        {
            required[c - 'a']++;
        }

        int cnt = INT_MAX;
        for (char c : balloon)
        {
            int instances = temp[c - 'a'] / required[c - 'a'];
            cnt = min(cnt, instances);
        }

        return cnt;
    }
};