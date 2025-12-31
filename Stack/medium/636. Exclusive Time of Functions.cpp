#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    pair<pair<int,string>,int> parse(string str){
        string id = "" , event = "" , time="";
        int i=0;
        while(i<str.size()){
            while(i<str.size() && str[i]!=':'){
                id+=str[i++];
            }
            i++;
            while(i<str.size() && str[i]!=':'){
                event+=str[i++];
            }
            i++;
            while(i<str.size()){
                time+=str[i++];
            }
        }

        return {{stoi(id),event},stoi(time)};
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>res(n,0);
        stack<int>s;
        int current = 0;
        for(int i=0;i<logs.size();i++){
            auto const &p= parse(logs[i]);
            
            int id = p.first.first;
            string event = p.first.second;
            int time = p.second;
            
            if(event == "start"){
                if(s.size()){
                    res[s.top()]+= (time-current);
                }
                s.push(id);
                current = time;
            }else{
                if(s.size()){
                    res[s.top()]+=(time-current+1);
                }
                s.pop();
                current = time+1; 
            }
        }

        return res;
    }
};