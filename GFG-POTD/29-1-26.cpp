#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    string firstNonRepeating(string &s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        
        vector<int>track(26,0);
        
        string res = "";
        
        for(int j=0;j<n;j++){
            char c = s[j];
            
            track[c-'a']++;
            
            while(i<j && track[s[i]-'a'] > 1){
                // track[s[i]-'a']--;
                i++;
            }
            
            if(i<=j && track[s[i]-'a'] == 1){
                res.push_back(s[i]);
            }else{
                res.push_back('#');
            }
        }
        
        return res;
    }
};