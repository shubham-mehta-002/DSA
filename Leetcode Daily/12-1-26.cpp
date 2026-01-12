#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total = 0;
        for(int i=1;i<points.size();i++){
            int diffI = abs(points[i][0] - points[i-1][0]);
            int diffJ = abs(points[i][1] - points[i-1][1]);

            if(diffI > diffJ){
                total += diffJ;
                total += (diffI-diffJ);
            }else if(diffI < diffJ){
                total += diffI;
                 total += (diffJ-diffI);
            }else{
                total += diffI;
            }
        }
        return total;
    }
};