#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>>res;

        int minDiff = INT_MAX;
        for(int i=1;i<arr.size();i++){
            if(arr[i] - arr[i-1] <= minDiff){
                minDiff = arr[i] - arr[i-1];
                while(res.size() && (res[res.size()-1][1] - res[res.size()-1][0]) > minDiff){
                    res.pop_back();
                }

                res.push_back({arr[i-1] , arr[i]});
            }
        }


        return res;
    }
};