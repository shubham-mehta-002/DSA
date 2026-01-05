#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>res(n);
        stack<pair<int,int>>st;
        int time = 0;
        for(int i=n-1; i>=0; i--){
            time++;
            while(!st.empty() && temperatures[i] >= st.top().first){
                st.pop();
            }

            if(st.size()){
                res[i] = time - st.top().second;
            }else{
                res[i] = 0;
            }

            st.push({temperatures[i] , time});
        }
        return res;
    }
};