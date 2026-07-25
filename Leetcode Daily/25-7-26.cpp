#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(int n)
    {
        int a = 0, b = 0;

        while (n)
        {
            int rem = n % 10;
            n /= 10;

            if (rem > a)
            {
                b = a;
                a = rem;
            }
            else if (rem > b)
            {
                b = rem;
            }
        }

        return a * b;
    }
};