#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &a, vector<int> &b)
    {
        unordered_set<int> st;
        vector<int> res;
        for (int n : a)
        {
            st.insert(n);
        }

        for (int n : b)
        {
            if (st.find(n) != st.end())
            {
                res.push_back(n);
                st.erase(n);
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};