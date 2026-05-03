#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int find(int index, bool tight, int oneCount, string &str, vector<vector<vector<int>>> &mem)
    {
        if (index == str.size())
            return oneCount;

        if (mem[index][tight][oneCount] != -1)
        {
            return mem[index][tight][oneCount];
        }
        int lb = 0;
        int ub = (tight ? str[index] - '0' : 9);

        int total = 0;
        for (int dig = lb; dig <= ub; dig++)
        {
            total += find(index + 1, (dig == str[index] - '0' && tight), oneCount + (dig == 1), str, mem);
        }

        return mem[index][tight][oneCount] = total;
    }

    int countDigitOne(int n)
    {
        string str = to_string(n);

        // mem[index][tight][noOf1s]
        // max val -> 1e9 ie maxNoOfDigits = 10
        vector<vector<vector<int>>> mem(10, vector<vector<int>>(2, vector<int>(9, -1)));

        return find(0, true, 0, str, mem);
    }
};