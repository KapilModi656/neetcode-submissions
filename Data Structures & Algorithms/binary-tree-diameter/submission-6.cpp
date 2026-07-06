/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int depth(TreeNode* root,int& maxim){
        if(root==NULL) return 0;
        int maxi = 0;
        int left = depth(root->left,maxim);
        int right = depth(root->right,maxim);
        maxim = max(maxim,left+right);
        maxi = max(left,right);
        return 1+maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi = 0;
        depth(root,maxi);
        return maxi;
    }
};
