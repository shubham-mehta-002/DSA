#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        vector<int> diff(n, 0);

        for (auto s : shifts)
        {
            int operation = (s[2] == 0 ? -1 : 1);
            diff[s[0]] += operation;
            if (s[1] + 1 < n)
            {
                diff[s[1] + 1] += (-1 * operation);
            }
        }

        int prefixSum = 0;
        string res = "";
        for (int i = 0; i < n; i++)
        {
            cout << diff[i] << " ";
            prefixSum += diff[i];
            diff[i] = prefixSum;

            int originalVal = s[i] - 'a';
            int shiftedVal = originalVal + diff[i];
            shiftedVal = (shiftedVal % 26 + 26) % 26;

            char c = shiftedVal + 'a';

            res.push_back(c);
        }

        return res;
    }
};