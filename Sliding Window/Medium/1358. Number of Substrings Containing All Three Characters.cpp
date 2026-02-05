#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int j = 0;
        vector<int>lastSeen(3,-1);
        int count = 0; 
        while(j<n){
            lastSeen[s[j]-'a']=j;

            int minLastSeen = min({
                lastSeen[0],
                lastSeen[1],
                lastSeen[2]
            });

            if(minLastSeen != -1){
                count += minLastSeen+1;
            }
            j++;
        }
        return count;
    }
};