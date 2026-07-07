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
    int solve(TreeNode* root,bool taken,map<TreeNode*,map<bool,int>>& dp){
        if(root==NULL) return 0;
        if(dp.count(root)&&dp[root].count(taken)) return dp[root][taken];
        int optim = solve(root->right,false,dp)+solve(root->left,false,dp);
        if(taken){
            dp[root][taken] = optim;
            return optim;
        }
        int optimal = root->val + solve(root->left,true,dp)+solve(root->right,true,dp);
        return dp[root][taken] = max(optim,optimal);
        
    }
    int rob(TreeNode* root) {
        map<TreeNode*,map<bool,int>> dp;
        return solve(root,false,dp);
    }
};