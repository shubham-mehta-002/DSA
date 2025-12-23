#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dx= {0,1,0,-1};
    vector<int> dy= {1,0,-1,0};

public:
    void mark(vector<vector<char>>&board, vector<vector<int>>&vis,int row, int col){
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty()){
            pair<int,int>&p = q.front();
            for(int i = 0 ;i <4;i++){
                int new_r = p.first + dx[i];
                int new_c = p.second + dy[i];

                if(new_r >=0  && new_c>=0 && new_r<m && new_c<n && !vis[new_r][new_c] && board[new_r][new_c] == 'O'){
                    vis[new_r][new_c] = 1;
                    q.push({new_r,new_c});
                }
            }
            q.pop();
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        
        // upper and bottom edges
        // first row,all columns
        for(int c=0;c<n;c++){
            if(board[0][c] == 'O'){
                vis[0][c]=1;
                mark(board,vis,0,c);
            }
        }
        // last row, all columns
        for(int c=0;c<n;c++){
            if(board[m-1][c] == 'O'){
                vis[m-1][c]=1;
                mark(board,vis,m-1,c);
            }
        }

        // left and right edges
        // (1 to m-1)row, 0th col
        for(int r=1;r<m-1;r++){
            if(board[r][0] == 'O'){
                vis[r][0]=1;
                mark(board,vis,r,0);
            }
        }

        // (1 to m-1) row, last col
        for(int r=1;r<m-1;r++){
            if(board[r][n-1] == 'O'){
                vis[r][n-1]=1;
                mark(board,vis,r,n-1);
            }
        }



        for(int i=0;i<m;i++){
            for(int j = 0; j<n;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};