#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int i = 0;
        while(tickets[k] != 0){
            if(tickets[i] != 0){
                time++;
                tickets[i]--;
            }
            i++;
            if(i==tickets.size()){
                i = 0;
            }
        }

        return time;
    }
};