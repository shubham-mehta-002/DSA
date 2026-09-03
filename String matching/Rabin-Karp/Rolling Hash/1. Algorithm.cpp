#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution
{
    const int PRIME = 31;

    ll getHash(int i, int j, string &txt)
    {
        ll hash = 0;

        for (int index = i; index <= j; index++)
        {
            hash *= PRIME;
            hash += (txt[index] - 'a');
        }

        return hash;
    }

    ll getMaxPowerValue(int len)
    {
        ll res = 1;

        for (int i = 0; i < len; i++)
        {
            res *= PRIME;
        }

        return res;
    }

    bool isEqual(int start, int len, string &txt, string &pat)
    {
        for (int i = 0; i < len; i++)
        {
            if (pat[i] != txt[start + i])
            {
                return false;
            }
        }

        return true;
    }

    ll updateHash(ll currentHash, ll maxPowerValue, int prevVal, int newVal)
    {
        currentHash -= (prevVal * maxPowerValue);
        currentHash *= PRIME;
        currentHash += newVal;
        return currentHash;
    }

public:
    vector<int> search(string &pat, string &txt)
    {

        vector<int> res;

        int patLen = pat.size();

        if (patLen > txt.size())
        {
            return res;
        }

        ll patternHash = getHash(0, patLen - 1, pat);
        ll windowHash = getHash(0, patLen - 1, txt);

        ll maxPowerValue = getMaxPowerValue(patLen - 1);

        // First window
        if (windowHash == patternHash && isEqual(0, patLen, txt, pat))
        {
            res.push_back(0);
        }

        // Sliding window
        for (int index = patLen; index < txt.size(); index++)
        {

            windowHash = updateHash(
                windowHash,
                maxPowerValue,
                txt[index - patLen] - 'a',
                txt[index] - 'a');

            int start = index - patLen + 1;

            if (windowHash == patternHash && isEqual(start, patLen, txt, pat))
            {
                res.push_back(start);
            }
        }

        return res;
    }
};