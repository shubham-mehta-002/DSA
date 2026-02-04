#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> track;

        int i = 0;
        int j = 0;
        int n = s.size();
        int maxLen = 0;
        while(j < n){
            char c = s[j];

            while(track[c] > 0){
                track[s[i]]--;
                i++;
            }

            maxLen = max(maxLen,j-i+1);
            track[c]++;
            j++;
        }
        return maxLen;
    }
};