#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        vector<int>res(nums1.size(),-1);

        stack<int>st;

        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                m[nums2[st.top()]] = nums2[i];
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty()){
            m[nums2[st.top()]] = -1;
            st.pop();
        }

        for(int i=0;i<nums1.size();i++){
            res[i] = m[nums1[i]];
        }

        return res;

    }
};