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
    bool solve(TreeNode* root,int mini,int maxi) {
        if(root==NULL) return true;
        if(root->val>=maxi) return false;
        if(root->val<=mini) return false;
        if(root->left){
            if(root->left->val>=root->val) return false;
        }
        if(root->right){
            if(root->right->val<=root->val) return false;
        }
        return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};
