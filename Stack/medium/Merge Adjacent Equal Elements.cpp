#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;

        stack<long long>st;
        for(int n : nums){

            long long val = n;

            while(!st.empty() && st.top() == val){
                st.pop();
                val *=2;
            }

            st.push(val);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};