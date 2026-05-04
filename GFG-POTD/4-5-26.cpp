#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPallindrome(long long int N)
    {
        long long int org = N;
        long long rev = 0;

        while (org)
        {
            int bit = org & 1;
            rev <<= 1;
            rev |= bit;
            org >>= 1;
        }

        return rev == N;
    }
};