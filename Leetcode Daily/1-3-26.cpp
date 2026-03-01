#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPartitions(string n)
    {
        int val = 0;
        for (char c : n)
        {
            val = max(val, c - '0');
        }
        return val;
    }
};