#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int hour = -1;
        int penalty = 0;
        int minPenalty = 0;

        for(int i = 0 ; i <customers.size(); i++){
            if(customers[i] == 'Y'){
                penalty--;
            }else{
                penalty++;
            }

            if(penalty < minPenalty){
                minPenalty = penalty;
                hour = i;
            }
        }

        return hour+1;
    }
};