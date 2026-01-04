#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(int num : nums){
            int count = 0;
            int sum = 0;
            for(int i=1; i<=sqrt(num);i++){
                if(num%i == 0){
                    sum+=i;
                    count++;
                    if(i != num/i){
                        sum+=num/i;
                        count++;
                    }
                }
            }
        
            if(count==4){
                
                total+=sum;
            }
        }

        return total;
    }
};