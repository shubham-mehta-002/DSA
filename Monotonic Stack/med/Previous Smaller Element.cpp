#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int>pse(n,-1);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            
            pse[i] = st.empty() ? -1 : st.top();
            
            st.push(arr[i]);
        }
        
        return pse;
    }
};