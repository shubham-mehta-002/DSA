#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool pythagoreanTriplet(vector<int> &arr)
    {
        unordered_set<int> st;
        for (int a : arr)
        {
            st.insert(a * a);
        }

        for (int i : st)
        {
            for (int j : st)
            {
                if (i != j)
                {
                    if (st.count(i + j))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};