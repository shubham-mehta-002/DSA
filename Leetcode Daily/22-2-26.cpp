#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        int dist = 0;
        bitset<31> bt(n);
        int i = 0;

        while (i <= 31 && bt[i] != 1)
        {
            i++;
        }

        for (int j = i + 1; j < 32; j++)
        {
            if (bt[j] == 1)
            {
                dist = max(dist, j - i);
                i = j;
            }
        }

        return dist;
    }
};