#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int temp = start ^ goal;
        int count;
        while (temp)
        {
            if (temp & 1 == 1)
                count++;
            temp >>= 1;
        }

        return count;
    }
};