#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>>res;
  public:
    void find(vector<int>&arr, vector<bool>&vis, vector<int>& v){
        if(v.size() == arr.size()){
            vector<int>temp(v.begin(),v.end());
            res.push_back(temp);
            return;
        }
        
        
        for(int i=0;i<arr.size();i++){
            if(!vis[i]){
                vis[i] = true;
                v.push_back(arr[i]);
                find(arr,vis,v);
                v.pop_back();
                vis[i] = false;
            }
        }
        
        
    }
    
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<bool>vis(arr.size(),false);
        vector<int>v;
        find(arr,vis,v);
        return res;
    }
};