#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> mpp;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mpp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        int l = 0;
        int h = mpp[key].size() - 1;

        int ans = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2;

            if (mpp[key][mid].first > timestamp)
            {
                h = mid - 1;
            }
            else
            {
                ans = mid;
                l = mid + 1;
            }
        }

        return ans == -1 ? "" : mpp[key][ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */