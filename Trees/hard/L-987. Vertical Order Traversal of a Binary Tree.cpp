#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)   return res;

        int minCol = INT_MAX;
        int maxCol = INT_MIN;

        unordered_map<int, priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> > m;
        queue<pair<int,TreeNode*>> q; // {colIndex , Node}
        q.push({0,root});
        int rowCount = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                const pair<int,TreeNode*>&p = q.front();
                minCol = min(minCol, p.first);
                maxCol = max(maxCol, p.first);
                // cout<<minCol<<" "<<maxCol<<"\n";
                m[p.first].push({rowCount,p.second->val});

                if(p.second->left){
                    q.push({p.first-1 , p.second->left});
                }
                if(p.second->right){
                    q.push({p.first+1 , p.second->right});
                }
                q.pop();
            }
            rowCount++;
        }


        for(int col = minCol ; col<= maxCol ; col++){
            vector<int>level;
            auto &pq = m[col];
            while(!pq.empty()){
                level.push_back(pq.top().second);
                pq.pop();
            }
            res.push_back(level);
        }

        return res;



    }
};