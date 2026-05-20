#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int t1 = 0;
        int t2 = 0;

        for (int a : A)
        {
            t1 = t1 | 1 << a;
        }

        for (int b : B)
        {
            t2 = t2 | 1 << b;
        }
    }
};