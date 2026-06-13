#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(string &word, vector<int> &weights)
    {
        int sum = 0;
        for (char c : word)
        {
            sum += weights[c - 'a'];
        }
        sum %= 26;
        return (char)(26 - sum + 'a' - 1);
    }
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string str = "";
        for (string &word : words)
        {
            str += find(word, weights);
        }

        return str;
    }
};