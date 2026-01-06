#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3){
            return false;
        }

      
        int i=1;
        int n = arr.size();
        while(i<n-1 && arr[i-1] < arr[i]){
            i++;
        }

        if(i == n || i==1){
            return false;
        }
        
        while(i<n && arr[i-1] > arr[i]){
            i++;
        }

        if(i != n){
            return false;
        }

        return true;
    }
};