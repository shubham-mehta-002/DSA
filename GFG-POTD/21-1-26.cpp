#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // This problem is same as finding Previous greater element using monotonic stack
        stack<int>st;
        int n = arr.size();
        vector<int>res(n,-1);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                res[st.top()] = st.top() - i;
                st.pop();
            }
            
            st.push(i);
        }
        
        int i = -1; // assume this is as the new low
        while(!st.empty()){
            res[st.top()] = st.top() - i;
            st.pop();
        }
        
        return res;
    }
};