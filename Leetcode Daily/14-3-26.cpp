#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string find(string &temp, int size, int &target)
    {
        if (temp.size() == size)
        {
            target--;
            if (target == 0)
            {
                return temp;
            }
            return "";
        }

        for (int i = 0; i < 3; i++)
        {
            char c = i + 'a';
            if (temp.size() == 0 || c != temp[temp.size() - 1])
            {
                temp += (char)(i + 'a');
                string res = find(temp, size, target);
                if (res != "")
                {
                    return res;
                }
                temp.pop_back();
            }
        }
        return "";
    }
    string getHappyString(int n, int k)
    {
        string temp = "";
        return find(temp, n, k);
    }
};