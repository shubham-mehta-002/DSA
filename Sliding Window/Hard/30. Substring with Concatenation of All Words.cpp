#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;

        unordered_map<string, int> target;
        for (string str : words)
        {
            target[str]++;
        }

        int wordLength = words[0].size();
        for (int offset = 0; offset < wordLength; offset++)
        {
            int i = offset;
            int j = offset;
            int n = s.size();
            int count = 0;

            unordered_map<string, int> required = target;

            while (j < n)
            {
                string temp = s.substr(j, wordLength);

                if (required.find(temp) != required.end())
                {
                    while (required[temp] <= 0)
                    {
                        string temp2 = s.substr(i, wordLength);
                        required[temp2]++;
                        count--;
                        i += wordLength;
                    }

                    if (required[temp] > 0)
                    {
                        count++;
                        required[temp]--;
                        j += wordLength;
                    }

                    if (count == words.size())
                    {
                        res.push_back(i);
                    }
                }
                else
                {
                    i = j + wordLength;
                    j = i;
                    required = target;
                    count = 0;
                }
            }
        }

        return res;
    }
};