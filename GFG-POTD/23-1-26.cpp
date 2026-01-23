#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        stack<int>st;
        int n = arr.size();
        vector<int>res(n,-2);
        int maxCount = INT_MIN;
        int i = 0;
        while(i < n){
            while(!st.empty() && arr[i] >= arr[st.top()]){
                if(arr[i] == arr[st.top()]){
                    res[i] = st.top();
                }
                
                res[st.top()] = i - res[st.top()] -1;
                maxCount = max(res[st.top()], maxCount);
                st.pop();
            }
            
            if(res[i]== -2) res[i] = (st.empty() ? -1 : st.top());
            st.push(i);
            i++;
        }
        
        while(!st.empty()){
            res[st.top()]  = i - res[st.top()] - 1;
            maxCount = max(res[st.top()],maxCount);
            st.pop();
        }
       
        return maxCount;
    }
};