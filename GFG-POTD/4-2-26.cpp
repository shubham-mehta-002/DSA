#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int val = 0;
        
        for(int l : left){
            val = max(val,l);
        }
        
        for(int r : right){
            val = max(val, n-r);
        }
        
        return val;
    }
};