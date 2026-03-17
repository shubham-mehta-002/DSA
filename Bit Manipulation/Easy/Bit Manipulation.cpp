#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bitManipulation(int num, int i)
    {
        int mask = 1;

        cout << ((num >> i - 1) & 1) << " ";
        cout << (num | (mask << i - 1)) << " ";

        cout << (num & ~(mask << i - 1));
    }
};