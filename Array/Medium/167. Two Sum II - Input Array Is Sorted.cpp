#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> res;
        int n = numbers.size();
        int i = 0;
        int j = n - 1;

        while (i <= j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
            {
                res.push_back(i + 1);
                res.push_back(j + 1);
                return res;
            }
            else if (sum > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return res;
    }
};