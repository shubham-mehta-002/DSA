#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int,int>m;
        int i=0; 
        int j=0;
        int distinct = 0;
        vector<int>res;
        while(j < arr.size()){
            if(m[arr[j]] == 0){
                distinct++;
            }
            m[arr[j]]++;
            
            if(j-i+1 == k){
                res.push_back(distinct);
                if(m[arr[i]] == 1){
                    distinct--;
                }
                m[arr[i]]--;
                i++;
            }
            j++;
        }
        
        return res;
        
    }
};