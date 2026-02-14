#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int>pos;
        vector<int>neg;
        
        for(int a : arr){
            if(a >=0){
                pos.push_back(a);
            }else{
                neg.push_back(a);
            }
        }
        
        if(pos.size() == 0 || neg.size() == 0){
            return;
        }
        
        
        int p = 0;
        int n = 0;
        int i=0;
        
        
        int limit = min(pos.size(),neg.size())*2;
        
        while(i< limit){
            arr[i++] = pos[p++];
            arr[i++] = neg[n++];
        }
        
        while(p < pos.size()){
            arr[i++] = pos[p++];
        }
        
        while(n < neg.size()){
            arr[i++] = neg[n++];
        }
    }
};