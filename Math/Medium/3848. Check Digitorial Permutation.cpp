
#include <bits/stdc++.h>
using namespace std;

class Solution

{
public:
    unordered_map<int, int> mpp;

    int fact(int num)
    {
        if (num == 0)
        {
            return 1;
        }
        if (mpp[num] != 0)
        {
            return mpp[num];
        }
        return mpp[num] = num * fact(num - 1);
    }
    int findFact(int n)
    {
        int sum = 0;
        while (n)
        {
            int dig = n % 10;
            n /= 10;
            sum += fact(dig);
        }

        return sum;
    }
    bool findIfPermutation(int n, int fact)
    {
        unordered_map<int, int> mpp;

        int temp = n;
        while (temp)
        {
            int rem = temp % 10;
            mpp[rem]++;
            temp /= 10;
        }

        temp = fact;
        while (temp)
        {
            int rem = temp % 10;
            if (mpp[rem] == 0)
                return false;
            mpp[rem]--;
            if (mpp[rem] == 0)
            {
                mpp.erase(rem);
            }
            temp /= 10;
        }

        return mpp.empty();
    }

    bool isDigitorialPermutation(int n)
    {
        int fact = findFact(n);
        cout << fact;
        return findIfPermutation(n, fact);
    }
};