#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calcOnBits(int val)
    {
        int count = 0;
        while (val)
        {
            val &= (val - 1);
            count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [this](const int &a, const int &b)
             {
            int b1 = calcOnBits(a);
            int b2 = calcOnBits(b);
        
            if(b1 == b2){
                return (a < b);
            }
            if(b1 < b2){
                return true;
            }
            return false; });

        return arr;
    }
};