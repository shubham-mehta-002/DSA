#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        vector<int>candy(n,1);
        int total = 0;
        
        for(int i=1;i<arr.size();i++){
            if(arr[i] > arr[i-1]){
                candy[i] = max(candy[i-1]+1, candy[i]);
            }
        }
        
        
        for(int i=n-2;i>=0;i--){
            if(arr[i] > arr[i+1]){
                candy[i] = max(candy[i+1]+1, candy[i]);
            }
        }
        
        for(int c : candy){
            total+=c;
        }
        
        return total;
        
    }
};