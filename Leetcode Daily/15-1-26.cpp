#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& bars) {
        sort(bars.begin(), bars.end());

        int best = 1, cur = 1;
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                cur++;
            } else {
                cur = 1;
            }
            best = max(best, cur);
        }
        return best;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxY = hBars.empty() ? 1 : longestConsecutive(hBars) + 1;
        int maxX = vBars.empty() ? 1 : longestConsecutive(vBars) + 1;

        int side = min(maxX, maxY);
        return side * side;
    }
};
