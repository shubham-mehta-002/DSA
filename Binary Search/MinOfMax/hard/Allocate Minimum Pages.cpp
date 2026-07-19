#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    using ll = long long;

    bool isValid(ll maxPages, vector<int> &arr, int k)
    {
        int students = 1;
        ll pages = 0;

        for (int book : arr)
        {
            if (pages + book <= maxPages)
            {
                pages += book;
            }
            else
            {
                students++;
                pages = book;

                if (students > k)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int> &arr, int k)
    {
        int n = arr.size();

        if (k > n)
            return -1;

        ll low = *max_element(arr.begin(), arr.end());
        ll high = accumulate(arr.begin(), arr.end(), 0LL);

        ll ans = high;

        while (low <= high)
        {
            ll mid = low + (high - low) / 2;

            if (isValid(mid, arr, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};