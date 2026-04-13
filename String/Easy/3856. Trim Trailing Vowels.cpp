#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string trimTrailingVowels(string s)
    {
        int i = s.size() - 1;
        while (i >= 0 && isVowel(s[i]))
        {
            i--;
        }

        if (i == -1)
            return "";

        string res = "";
        for (int j = 0; j <= i; j++)
        {
            res += s[j];
        }

        return res;
    }
};