#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int n : nums)
        {
            s.insert(n);
        }

        unordered_map<int, int> m;
        int maxCount = 0;

        for (int n : nums)
        {
            int count = 0;
            int val = n;
            while (s.find(val) != s.end())
            {
                count++;
                s.erase(val);
                val++;
            }
            count += m[val];
            m[n] = count;
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};