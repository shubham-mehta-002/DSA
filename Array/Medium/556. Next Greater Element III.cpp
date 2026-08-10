#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string str = to_string(n);

        int size = str.size();
        int index = size - 2;

        while (index >= 0 && str[index] >= str[index + 1])
        {
            index--;
        }

        if (index == -1)
        {
            return -1;
        }

        int idx = index + 1;

        // find char just greater than this pivot index
        int justGreater = -1;
        for (int p = size - 1; p >= idx; p--)
        {
            if (str[p] <= str[index])
            {
                continue;
            }
            else
            {
                justGreater = p;
                break;
            }
        }

        // swap
        swap(str[index], str[justGreater]);

        // reverse the rest string
        reverse(str.begin() + index + 1, str.end());

        long res = 0;
        for (int i = 0; i < size; i++)
        {
            res *= 10;
            res += (str[i] - '0');

            if (res > INT_MAX)
            {
                return -1;
            }
        }
        return (int)res;
    }
};