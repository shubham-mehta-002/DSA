#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int>res;
        int n1 = a.size();
        int n2 = b.size();
        
        int i=0;
        int j=0;
        int ptr = 0;
        
        while(i<n1 && j<n2){
            if(a[i] <= b[j]){
                if(res.size() == 0){
                    res.push_back(a[i]);
                }else if(res.back() != a[i]){
                    res.push_back(a[i]);
                }
                i++;
            }else{
                if(res.size() == 0){
                    res.push_back(b[j]);
                }else if(res.back() != b[j]){
                    res.push_back(b[j]);
                }
                j++;
            }
        }
        
        while(i<n1){
            if(res.size() == 0){
                res.push_back(a[i]);
            }else if(res.back() != a[i]){
                res.push_back(a[i]);
            }
            i++;
        }
        
        while(j<n2){
            {
                if(res.size() == 0){
                    res.push_back(b[j]);
                }else if(res.back() != b[j]){
                    res.push_back(b[j]);
                }
                j++;
            }
        }
        
        
        
        return res;
    }
};