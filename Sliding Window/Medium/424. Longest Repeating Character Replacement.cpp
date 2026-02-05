#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxLen = 0;
        int maxCount = 0;

        unordered_map<int,int>m;

        while(j<n){
            m[s[j]]++;
            
            maxCount = max(maxCount,m[s[j]]);

            int others = j-i+1 - maxCount;

            if(others > k){
                m[s[i]]--;
                i++;
            }else{
                maxLen = max(maxLen, j-i+1);
            }

            j++;

        }

        return maxLen;
    }
};