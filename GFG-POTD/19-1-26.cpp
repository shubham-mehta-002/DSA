#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        string res = "";
        if(s.size() <= k){
            return "0";
        }
        stack<char>st;
        int count = k;
        int i=0;
        while(i < s.size()){
            while(!st.empty() && st.top() > s[i] && count){
                st.pop();
                count--;
            }
            
            st.push(s[i]);
            ++i;
        }
        // cout<< st.size()<<" \n";
        while(count && !st.empty()){
            st.pop();
            count--;
        }
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        
        
        while(res.size() && res[res.size()-1] == '0'){
            res.pop_back();
        }
        
        if(res.size() == 0){
            return "0";
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};