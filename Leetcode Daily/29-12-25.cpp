#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, vector<char>> combinations;

public:
    bool find(string bottom, int current, int end,
              unordered_map<string, bool>& bad) {

        if (end == 0) return true;

        if (bad.count(bottom))
            return false;

        string base = bottom.substr(current, 2);
        if (!combinations.count(base))
            return bad[bottom] = false;

        char old = bottom[current];  // for backtracking
        for (char c : combinations[base]) {
            bottom[current] = c;

            bool found;
            if (current + 1 == end)
                found = find(bottom.substr(0, end), 0, end - 1, bad);
            else
                found = find(bottom, current + 1, end, bad);

            if (found)
                return true;
            
            bottom[current] = old;
        }

        return bad[bottom] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string& a : allowed)
            combinations[a.substr(0, 2)].push_back(a[2]);

        unordered_map<string, bool> bad;
        return find(bottom, 0, bottom.size() - 1, bad);
    }
};
