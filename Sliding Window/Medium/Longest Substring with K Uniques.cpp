#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int>m;
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxLen = -1;
        
        while(j<n){
            m[s[j]]++;
            
            if(m.size() > k){
                m[s[i]]--;
                if(m[s[i]] == 0){
                    m.erase(s[i]);
                }
                
                i++;
            }
            
            if(m.size() == k){
                maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
        
        return maxLen;
    }
};