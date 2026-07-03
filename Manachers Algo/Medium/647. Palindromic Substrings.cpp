#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        string t = "";
        t += '#';
        for (char c : s)
        {
            t += c;
            t += '#';
        }

        int n = t.size();
        vector<int> p(n, 0);

        int right = 0;
        int center = 0;

        int cnt = 0;

        for (int index = 0; index < n; index++)
        {
            int mirror = 2 * center - index;

            if (index < right)
            {
                p[index] = min(p[mirror], right - index);
            }

            int a = index + p[index] + 1;
            int b = index - p[index] - 1;
            while (b >= 0 && a < n && t[a] == t[b])
            {
                a++;
                b--;
                p[index]++;
            }

            if (index + p[index] > right)
            {
                center = index;
                right = p[index] + index;
            }

            cnt += (p[index] + 1) / 2;
        }

        return cnt;
    }
};