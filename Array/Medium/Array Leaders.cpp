#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int>res;
        int n = arr.size();
        int maxVal = INT_MIN;
        
        for(int i=n-1; i>=0; i--){
            if(arr[i] >= maxVal){
                res.insert(res.begin(), arr[i]);
            }
            
            maxVal = max(maxVal ,arr[i]);
        }
        
        return res;
    }
};