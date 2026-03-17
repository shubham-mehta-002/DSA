#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkKthBit(int n, int k)
    {
        int mask = 1;
        return n & mask << k;
    }
};