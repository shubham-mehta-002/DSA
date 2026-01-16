
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int const MOD = (int)1e9+7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vector<int>xAxis;
        xAxis.push_back(1);
        for(int x : vFences){
            xAxis.push_back(x);
        }
        xAxis.push_back(n);

        vector<int>yAxis;
        yAxis.push_back(1);
        for(int x : hFences){
            yAxis.push_back(x);
        }
        yAxis.push_back(m);

        // find max Widths;
        unordered_map<int,int>edges;
        for(int i=0;i<xAxis.size();i++){
            for(int j=i+1; j<xAxis.size();j++){
                int diff = abs(xAxis[j] - xAxis[i]);
                edges[diff] = 1;
            }
        }
        
        long long maxArea = -1;
        // find max y-axis width;
        for(int i=0;i<yAxis.size();i++){
            for(int j=i+1; j<yAxis.size();j++){
                int diff = abs(yAxis[j] - yAxis[i]);
                // edges[diff] = 1;
                if(edges.count(diff)){
                    maxArea = max(maxArea , 1LL*diff*diff);
                }
            }
        }

        if(maxArea == -1){
            return -1;
        }else{
            return maxArea%MOD;
        }
    }
};