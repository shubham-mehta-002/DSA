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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root){
            return res;
        }

        queue<TreeNode*>q;
        q.push(root);
        bool found = true;
        while(!q.empty()){
            int size = q.size();
            found = false;
            while(size--){
                TreeNode* top = q.front();
                q.pop();
                if(top){
                    res+=(to_string(top->val) +  " ");
                    if(top->left || top->right){
                        found = true;
                    }
                    q.push(top->left);
                    q.push(top->right);
                }else{
                    res += "N ";
                }
            }
            if(!found){
                break;
            }
        }
        cout<<res;
        return res;
    }

    int getNextNumber(string data, int& index){
        string str="";
        while(data[index]!=' '){
            str+=data[index++];
        }
        index++; // to handle the space
        return stoi(str);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        TreeNode* root = NULL;
        if(data.size()==0){
            return root;
        }
        queue<TreeNode*>q;
        root = new TreeNode(getNextNumber(data,i));
        q.push(root);
        
        while(i<data.size()){
            TreeNode*leftNode = NULL, *rightNode = NULL;
            
            if(data[i] == 'N'){
                i+=2;
            }else{
                leftNode = new TreeNode(getNextNumber(data,i));
            }

            if(data[i] == 'N'){
                i+=2;
            }else{
                rightNode = new TreeNode(getNextNumber(data,i));
            }

            TreeNode* top = q.front();
            q.pop();
            top->left = leftNode;
            if(top->left) q.push(leftNode);

            top->right = rightNode;
            if(top->right) q.push(rightNode);
        }  

        return root;
    }
};
