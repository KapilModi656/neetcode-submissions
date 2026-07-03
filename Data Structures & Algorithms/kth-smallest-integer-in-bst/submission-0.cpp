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
    void solve(TreeNode* root,int k,int& curr,int& ans){
        if(root==NULL) return;
        if(root->left){
            solve(root->left,k,curr,ans);
        }
        curr++;
        if(k==curr){
            ans=root->val;
        }
        if(root->right){
            solve(root->right,k,curr,ans);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int curr=0;
        solve(root,k,curr,ans);
        return ans;
    }
};
