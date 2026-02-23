#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        unordered_set<string> st;

        int i = 0;
        int j = 0;
        int n = s.size();

        while (j < n)
        {
            if (j - i + 1 == k)
            {
                st.insert(s.substr(i, k));
                i++;
            }
            j++;
        }
        return (st.size() == pow(2, k));
    }
};