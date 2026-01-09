#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(string current, string endWord,unordered_map<string,int>&m,unordered_map<string,int>&vis){
        if(m.find(endWord) == m.end()){
            return 0;
        }
        queue<string>q;
        m[current] = 1;
        q.push(current);

        int n = current.size();

        int count = 0;
        while(!q.empty()){
            int size = q.size();
            count++;
            while(size--){
                string top = q.front();
                q.pop();
                if(top == endWord){
                    return count;
                }
                for(int i=0;i<n;i++){
                    char temp = top[i];
                    for(int c=0;c<26;c++){
                        top[i] = c + 'a';    
                        if(m.find(top) != m.end() && !vis[top]){
                            cout<<top<<" ";
                            vis[top] = 1;
                            q.push(top);
                        }
                    }   
                    top[i] = temp;
                }      
            }
        }
        // return vis[current]=minCount;
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // map all the words
        unordered_map<string,int>m;
        unordered_map<string,int>vis;
        for(string w : wordList){
            m[w] = 1;
            vis[w] = 0;
        }

        return bfs(beginWord,endWord,m,vis);  

    }
};