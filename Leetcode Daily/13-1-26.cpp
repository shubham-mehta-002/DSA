#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double check(double mid, vector<vector<int>>&squares){
        double area = 0;
        for(auto &s : squares){
            // auto [x1,y1,length] = s;
            double x = s[0];
            double y = s[1];
            double l = s[2];

            if(mid > (y+l)){
                area += l*l;
            }else if(mid < y){
                area += 0.0;
            }else{
                double new_l = (mid-y);
                area += (new_l*l);
            }
        }

        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double high = 0.00;
        double low = 0;
    
        double total = 0.0;
        for(auto &square : squares) {
            double x = square[0];
            double y = square[1];
            double l = square[2];
            total   += l*l;

            low  = min(low, y);
            high = max(high, y+l);
        }
        // double high = maxY;
        double mid = 0.00;
        while(abs(low-high) > 1e-5){
            mid = (low+high)/2.0;
            double area = check(mid,squares);
            if(area >= total/2.0){
                high = mid;
            }else{
                low = mid;
            }
        }

        return mid;
    }
};