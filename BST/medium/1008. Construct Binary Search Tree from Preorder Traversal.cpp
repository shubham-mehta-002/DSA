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
    int binarySearch(vector<int>&inorder, int target, int low, int high){
        while(low <= high){
            int mid = low + (high-low)/2;
            if(inorder[mid] == target){
                return mid;
            }else if(inorder[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return -1;
    }
    TreeNode* makeTree(vector<int>& preorder , vector<int>& inorder, int low, int high, int&counter){
        if(low < 0 || high >= inorder.size() || counter >= inorder.size()){
            return NULL;
        }
       
        int partition = binarySearch(inorder,preorder[counter] ,low,high);
        if(partition == -1){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[counter]);

        counter++;

        root->left = makeTree(preorder,inorder,low, partition-1,counter);
        root->right = makeTree(preorder,inorder, partition+1,high,counter);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        int n = inorder.size();
        int counter = 0;
        return makeTree(preorder, inorder, 0, n-1,counter);
    }
};