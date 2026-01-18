#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int,int> freq;
        vector<int>res(arr.size(),-1);
        int n = arr.size();
        for(int a : arr){
            freq[a]++;
        }      
        
        stack<int>st;
        
        int i=0;
        while(i<n){
            while(!st.empty() && freq[arr[st.top()]] < freq[arr[i]]){
                res[st.top()] = arr[i];        
                st.pop();
            }
                
            st.push(i);
            ++i;
        }
        
        return res;
    }
};
