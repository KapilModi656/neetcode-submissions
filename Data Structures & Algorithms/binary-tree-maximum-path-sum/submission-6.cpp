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
    int solve(TreeNode* root,int& maxi){
        if(root==NULL) return 0;
        int left = solve(root->left,maxi);
        int right = solve(root->right,maxi);
        int sumi=root->val;
        if(left>0) sumi+=left;
        if(right>0) sumi+=right;
        maxi =max(maxi, sumi);
        int pre = max(left,right);
        if(pre>0){
            return root->val + pre;
        }
        return root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};
