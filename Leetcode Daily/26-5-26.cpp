#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int a = 0;
        int b = 0;

        for (char w : word)
        {
            if (w >= 'a' && w <= 'z')
            {
                a = a | 1 << (w - 'a');
            }
            else
            {
                b = b | 1 << (w - 'A');
            }
        }

        int res = a & b;

        int count = 0;
        while (res)
        {
            count++;
            res &= (res - 1);
        }

        return count;
    }
};