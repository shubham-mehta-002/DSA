#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 && j >= 0)
        {
            int sum = carry + a[i] - '0' + b[j] - '0';
            cout << sum << " ";
            carry = sum / 2;
            int rem = sum % 2;

            res = char(rem + '0') + res;

            i--;
            j--;
        }

        while (i >= 0)
        {
            int sum = carry + a[i] - '0';
            carry = sum / 2;
            int rem = sum % 2;
            res = char(rem + '0') + res;

            i--;
        }
        while (j >= 0)
        {
            int sum = carry + b[j] - '0';
            carry = sum / 2;
            int rem = sum % 2;

            res = char(rem + '0') + res;

            j--;
        }

        if (carry)
        {
            res = '1' + res;
        }
        return res;
    }
};