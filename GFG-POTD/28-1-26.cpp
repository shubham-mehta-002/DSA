#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countSubset(vector<int> &arr, int k) {
        int n=arr.size();
        int mid=n/2;

        vector<int> left(arr.begin(),arr.begin()+mid);
        vector<int> right(arr.begin()+mid,arr.end());

        unordered_map<long long, int> mp;
        int m=right.size();

    
        for(int mask=0;mask<(1<<m);mask++){
            
            long long sum=0;
            for(int i=0;i<m;i++){
                if(mask &(1 << i)){
                    sum+=right[i];
                }
            }
            
            mp[sum]++;
        }

        int ans=0;
        int l=left.size();

 
        for(int mask=0;mask<(1<<l);mask++){
            
            long long sum=0;
            
            for(int i=0;i<l;i++){
                if(mask & (1<<i)) {
                    sum += left[i];
                }
            }
            
            ans+=mp[k-sum];
        }

        return ans;
    }
};