#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        unordered_set<int> toRemove;
        stack<int> st;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c >= 'a' && c <= 'z')
                continue;

            if (c == '(')
                st.push(i);
            if (c == ')')
            {
                if (st.empty())
                {
                    toRemove.insert(i);
                }
                else
                {
                    st.pop();
                }
            }
        }

        while (!st.empty())
        {
            toRemove.insert(st.top());
            st.pop();
        }

        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z')
            {
                res += ch;
            }
            else if (toRemove.find(i) != toRemove.end())
            {
                continue;
            }
            else
            {
                res += ch;
            }
        }

        return res;
    }
};