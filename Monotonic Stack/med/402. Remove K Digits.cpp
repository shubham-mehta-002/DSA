#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()){
            return "0";
        }

        stack<char>st;
        int count = k;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && count && st.top() > num[i]){
                st.pop();
                count--;
            }

            st.push(num[i]);
        }

        while(count){
            st.pop();
            count--;
        }

        if(st.empty()){
            return "0";
        }


        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        while(res.size() && res[res.size()-1] == '0') res.pop_back();

        reverse(res.begin(), res.end());
        return res.size() ? res : "0";
    }
};