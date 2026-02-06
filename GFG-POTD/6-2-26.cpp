#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    pair<int,int> find(int p1, int p2, int p3, vector<int>& a, vector<int>& b, vector<int>&c){
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        
        minVal = min({a[p1] , b[p2] , c[p3]});
        maxVal = max({a[p1] , b[p2] , c[p3]});
        
        return {minVal , maxVal};
    }
    
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        
        vector<int>res;
        
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        
        int n = a.size();
        
        int minDiff = INT_MAX;
        int minSum = INT_MAX;
        
        while(p1 < n && p2 < n && p3 < n){
            auto [minn,maxx] = find(p1,p2,p3,a,b,c);
            int sum = a[p1] + b[p2] + c[p3];
            int diff = maxx-minn;
            
            if (diff < minDiff || (diff == minDiff && sum < minSum)){
                minSum = sum;
                minDiff = diff;
                
                res.clear();
                res.push_back(a[p1]);
                res.push_back(b[p2]);
                res.push_back(c[p3]);
            }
            
            if (minn == a[p1]) p1++;
            else if (minn == b[p2]) p2++;
            else p3++;

            
        }
        
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        return res;
        
    }
};