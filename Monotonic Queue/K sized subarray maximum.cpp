#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int>dq;
        int i = 0;
        int j = 0;
        int n = arr.size();
        vector<int>res;
            
        while(j < n){
            while((!dq.empty() && arr[dq.back()] < arr[j])){
                dq.pop_back();
            }
            
            while(!dq.empty() && dq.front() <= j-k){
                dq.pop_front();
            }
            
            dq.push_back(j);
            
            if(j-i+1 == k){
                res.push_back(arr[dq.front()]);
                i++;
            }
            
            j++;
        }
        
        return res;
        
    }
};