#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int>res(n,-1);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            res[i] = st.empty() ? -1 : arr[st.top()];
            
            st.push(i);
        }
        
        return res;
        
    }
};