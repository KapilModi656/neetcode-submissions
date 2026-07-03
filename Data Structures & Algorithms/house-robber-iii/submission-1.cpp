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
    int solve(TreeNode* root,bool flag,map<TreeNode*,map<bool,int>>& dp){
        if(root==NULL) return 0;
        int ans=0;
        if(dp[root][flag]){
            return dp[root][flag];
        }
        if(!flag){
         
            ans=max(ans,root->val+solve(root->left,true,dp)+solve(root->right,true,dp));
        }
        ans=max(ans,solve(root->left,false,dp)+solve(root->right,false,dp));
        dp[root][flag]=ans;
        return dp[root][flag];
    }
    int rob(TreeNode* root) {
        bool flag=false;
        map<TreeNode*,map<bool,int>> dp;
        return solve(root,flag,dp);
    }
};