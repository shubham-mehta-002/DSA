// https://leetcode.com/problems/meeting-rooms-iii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>count(n,0);
        priority_queue< pair<long long,int> ,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        int roomWithMaxMeetings = -1;

        for(int i=0;i<n;i++){
            pq.push({0,i});
        }

        vector<pair<long long,int>>meets;
        for(auto meet : meetings){
            meets.push_back({meet[0] , meet[1]});
        }

        sort(meets.begin(),meets.end());

        for(auto meet : meets){
            while(!pq.empty() && pq.top().first < meet.first){
                auto [time,room] = pq.top();
                pq.pop();
                pq.push({meet.first,room});
            }

            auto [time,room] = pq.top();
            count[room]++;
            if(roomWithMaxMeetings == -1){
                roomWithMaxMeetings = room;
            }else if(count[room] > count[roomWithMaxMeetings] 
                || (count[room] == count[roomWithMaxMeetings] && room < roomWithMaxMeetings)){
                roomWithMaxMeetings = room;
            }

            pq.pop();

            if(time < meet.first){
                pq.push({meet.second,room});
            }else{  
                pq.push({meet.second-meet.first + time,room});
            }
        }
        return roomWithMaxMeetings;
    }
};