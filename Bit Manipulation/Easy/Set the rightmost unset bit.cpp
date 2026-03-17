#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBit(int n)
    {
        int mask = 1;
        int temp = n;
        while (temp && temp & 1 == 1)
        {
            mask <<= 1;
            temp >>= 1;
        }

        return (n | mask);
    }
};