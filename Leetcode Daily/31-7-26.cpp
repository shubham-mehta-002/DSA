#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> freq(26, 0);
        for (char c : word)
        {
            freq[c - 'a']++;
        }

        sort(freq.begin(), freq.end(), [](const int &a, const int &b)
             { return a > b; });

        int counter = 0;

        int ans = 0;
        for (int n : freq)
        {
            if (n == 0)
                break;
            counter++;
            int pressForOneTime = (counter % 8 == 0 ? counter / 8 : counter / 8 + 1);
            ans += (pressForOneTime * n);

            cout << ans << " ";
        }

        return ans;
    }
};