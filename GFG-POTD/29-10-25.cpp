#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int i = 0;
        int j = 0;
        int n1 = a.size();
        int n2 = b.size();
        int counter = 0;
        while(i<n1 && j<n2){
            
            if(a[i] < b[j]){
                counter++;
                if(counter == k){
                    return a[i];
                }
                i++;
            }else{
                counter++;
                if(counter == k){
                    return b[j];
                }
                j++;
            }
        }
        
        
        while(i<n1){
            counter++;
            if(counter == k){
                return a[i];
            }
            i++;
        }
        
        while(j<n2){
            counter++;
            if(counter == k){
                return b[j];
            }
            j++;
        }
        
        return -1;
    }
};