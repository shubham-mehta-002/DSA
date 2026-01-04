#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero = -1;
        int one = 0;
        int two = arr.size();
        
        while(one < two){
            if(arr[one] == 0){
                swap(arr[zero+1] , arr[one]);
                one++;
                zero++;
            }else if(arr[one] == 1){
                one++;
            }else{
                swap(arr[two-1] ,arr[one]);
                two--;
            }
        }
        
        return;
        
    }
};