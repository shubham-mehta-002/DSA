#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumIndex(vector<int> &capacity, int itemSize)
    {
        int index = -1;

        for (int i = 0; i < capacity.size(); i++)
        {
            if (capacity[i] >= itemSize)
            {
                if (index == -1)
                {
                    index = i;
                }
                else if (capacity[index] > capacity[i])
                {
                    index = i;
                }
            }
        }

        return index;
    }
};