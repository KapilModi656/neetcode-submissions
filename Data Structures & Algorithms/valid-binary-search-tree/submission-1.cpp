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
    bool solve(TreeNode* root,int mini,int maxi){
        if(root==NULL) return true;
       
        if(root->val<=mini||root->val>=maxi){
            return false;
        }
      
        bool flag1=solve(root->left,mini,root->val);
        bool flag2=solve(root->right,root->val,maxi);
        return flag1&&flag2;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,-2000,2000);
    }
};
