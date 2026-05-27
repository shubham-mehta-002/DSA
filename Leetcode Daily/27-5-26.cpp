#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        vector<int> temp(26, -1);

        int n = word.size();

        // Count total lowercase characters
        for (int i = 0; i < n; i++)
        {
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                m1[word[i]]++;
            }
        }

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            char ch = word[i];

            if (ch >= 'a' && ch <= 'z')
            {
                m2[ch]++;
                m1[ch]--;
            }
            else
            {
                char lower = ch - 'A' + 'a';

                if (m1[lower] > 0 && m2[lower] == 0 &&
                    (temp[ch - 'A'] == -1 || temp[ch - 'A'] == 1))
                {
                    temp[ch - 'A'] = 1;
                }
                else
                {
                    temp[ch - 'A'] = 0;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (temp[i] == 1)
                cnt++;
        }

        return cnt;
    }
};