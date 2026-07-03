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
    int depth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(depth(root->left),depth(root->right));
    }
    void level(TreeNode* root,vector<vector<int>>& ans,int l){
        if(root==NULL) return;
        ans[l].push_back(root->val);
        level(root->left,ans,l+1);
        level(root->right,ans,l+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n=depth(root);
        vector<vector<int>> ans(n);
        level(root,ans,0);
        return ans;

    }
};
