#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPosition(int n)
    {
        bitset<32> b(n);
        int idx = -1;

        for (int i = 0; i <= 31; i++)
        {
            if (b[i] == 1)
            {
                if (idx != -1)
                    return -1;
                else
                    idx = i + 1;
            }
        }

        return idx;
    }
};