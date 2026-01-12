#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxAreaOfReactangle(vector<int>&arr){
        int n = arr.size();
        vector<int>prefix(n,-1);
        vector<int>suffix(n,-1);

        stack<int>s;
        // suffix
        for(int i=0;i<n;i++){
            if(!s.empty()){
                int base = s.top();
                while(!s.empty() && arr[s.top()] > arr[i]){
                    suffix[s.top()] = base;
                    s.pop();
                }

            }
            s.push(i);
        }
        if(!s.empty()){
            int base = s.top();
            while(!s.empty()){
                suffix[s.top()]  = base;
                s.pop();
            }
        }

        // prefix
        for(int i=n-1;i>=0;i--){
            if(!s.empty()){
                int base = s.top();
                while(!s.empty() && arr[s.top()] > arr[i]){
                    prefix[s.top()] = base;
                    s.pop();
                }

            }
            s.push(i);
        }
        if(!s.empty()){
            int base = s.top();
            while(!s.empty()){
                prefix[s.top()]  = base;
                s.pop();
            }
        }


        int maxArea = INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxArea = max(maxArea , ((suffix[i] - prefix[i] + 1)*arr[i]));
        }

        // for(int a : prefix){
        //     cout << a <<" ";
        // }
        // cout<<endl;
        
        // for(int a : suffix){
        //     cout << a <<" ";
        // }
        return maxArea;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>level(matrix[0].size() , 0);
        int maxRect = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == '0'){
                    level[j] = 0;
                }else{
                    level[j] += 1;
                }
            }
            maxRect = max({
                maxRect,  
                findMaxAreaOfReactangle(level)
            }); 

        }
        return maxRect;
    }
};