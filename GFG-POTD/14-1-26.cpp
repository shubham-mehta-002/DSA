#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int t = 0;
        int p = 0;
        int caught = 0;
        int n = arr.size();
        
        while(t<n && p<n){
            while(t<n && arr[t]!='T') t++;
            
            while(p<n && arr[p]!='P') p++;
            
            if(!(p<n && t<n )){
                break;    
            }
            
            
            if(abs(t-p) <=k){
                t++;
                p++;
                caught++;
            }else if(t > p){
                p++;
            }else{
                t++;
            }
        }
        
        return caught;
    }
};