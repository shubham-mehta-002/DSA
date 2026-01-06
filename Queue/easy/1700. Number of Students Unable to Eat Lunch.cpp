#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int>count(2,0);
        for(int s : students){
            count[s]++;
        }

        for(int sand : sandwiches){
            if(count[sand]){
                count[sand]--;
            }else{
                break;
            }
        }
        return count[0] + count[1];
    }
};