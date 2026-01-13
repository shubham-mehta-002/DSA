#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int five = 0;
        int ten = 0;
  
        
        for(int a : arr){
            if(a == 5){
                five++;
            }else if(a == 10){
                if(five == 0){
                    return false;
                }
                
                five--;
                ten++;
            }else{
                int remaining = 15;
                if(ten > 0){
                    remaining -= 10;
                    ten--;
                }
                if(five > 0){
                    if(remaining / 5 > five){
                        return false;
                    }
                    five -= (remaining/5);
                 remaining = 0;
                }
                
                if(remaining > 0){
                    return false;
                }
            }
        }
        
        return true;
    }
};